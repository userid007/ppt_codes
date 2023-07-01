// Question-4:

// Write a program to connect nodes at the same level.
// Input:
//         1
//       /   \
//      2     3
//    /  \   /  \
//   4    5  6   7

// Output:

// 1 → -1
// 2 → 3
// 3 → -1
// 4 → 5
// 5 → 6
// 6 → 7
// 7 → -1

#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
  Node *connect(Node *root)
  {
    if (root == nullptr)
      return nullptr;
    if (root->left != nullptr)
      root->left->next = root->right;
    if (root->right != nullptr && root->next != nullptr)
      root->right->next = root->next->left;

    connect(root->left);
    connect(root->right);
    return root;
  }

  void printLevel(Node *root)
  {
    if (root == nullptr)
      return;

    Node *curr = root;
    while (curr != nullptr)
    {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout << endl;
    printLevel(root->left);
  }
};

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  Solution S;
  S.printLevel(S.connect(root));
  return 0;
}
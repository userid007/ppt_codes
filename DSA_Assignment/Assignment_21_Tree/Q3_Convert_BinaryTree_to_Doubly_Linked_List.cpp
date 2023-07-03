// Question-3:

// Write a program to convert a binary tree to a doubly linked list.

// Input:

//         10
//        /   \
//       5     20
//            /   \
//          30     35

// Output:
// 5 10 30 20 35

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
  int val;
  ListNode *next;
  ListNode *prev;
  ListNode() : val(0), next(nullptr), prev(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
  ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class Solution
{
public:
  ListNode *treeToDoublyList(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;

    vector<int> inorder = inorderTraversal(root);
    return createDoublyLinkedList(inorder);
  }

  void inorderTraversalhelper(TreeNode *root, vector<int> &ans)
  {
    if (root == nullptr)
      return;
    inorderTraversalhelper(root->left, ans);
    ans.push_back(root->val);
    inorderTraversalhelper(root->right, ans);
  }

  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    inorderTraversalhelper(root, ans);
    return ans;
  }

  ListNode *createDoublyLinkedList(vector<int> arr)
  {
    struct ListNode *head = nullptr, *temp = nullptr;
    for (int i = 0; i < arr.size(); i++)
    {
      if (head == nullptr)
        head = new ListNode(arr[i]);
      else if (temp == nullptr)
      {
        temp = new ListNode(arr[i]);
        temp->prev = head;
        head->next = temp;
      }
      else
      {
        temp->next = new ListNode(arr[i]);
        temp->next->prev = temp;
        temp = temp->next;
      }
    }
    return head;
  }

  void printLinkedList(ListNode *head)
  {
    while (head)
    {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }
};

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(30);
  root->right->right = new TreeNode(35);

  Solution S;
  ListNode *list = S.treeToDoublyList(root);
  S.printLinkedList(list);
  return 0;
}
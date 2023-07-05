// Given a Binary Tree, return Left view of it.
// Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
// The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \ 
//      2        3
//    /   \     /  \ 
//   4     5   6    7
//    \ 
//      8

// Example 1:

// Input:
//    1
//   / \ 
//  3   2
// Output: 1 3

// Example 2:

// Input:

//          10
//        /    \ 
//      20      30
//    /   \     
//   40   60
//
//
// Output: 10 20 40

#include <iostream>

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

class Solution
{
public:
  void leftViewUtil(TreeNode *root, vector<int> &leftV, int level, int *max_level)
  {
    if (root == nullptr)
      return;

    if (*max_level < level)
    {
      leftV.push_back(root->val);
      *max_level = level;
    }

    leftViewUtil(root->left, leftV, level + 1, max_level);
    leftViewUtil(root->right, leftV, level + 1, max_level);
  }

  vector<int> leftView(TreeNode *root)
  {
    vector<int> leftV;
    int max_level = 0;
    leftViewUtil(root, leftV, 1, &max_level);
    return leftV;
  }
};

int main()
{

  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(8);
  root->right->right = new TreeNode(15);
  root->right->left = new TreeNode(12);
  root->right->right->left = new TreeNode(14);

  Solution S;
  for (auto x : S.leftView(root))
    cout << x << " ";
  cout << endl;

  root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);
  for (auto x : S.leftView(root))
    cout << x << " ";
  cout << endl;

  root = new TreeNode(10);
  root->left = new TreeNode(20);
  root->right = new TreeNode(30);
  root->left->left = new TreeNode(40);
  root->left->right = new TreeNode(60);
  for (auto x : S.leftView(root))
    cout << x << " ";
  cout << endl;

  root = new TreeNode(4);
  root->left = new TreeNode(5);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(1);
  root->right->left->left = new TreeNode(6);
  root->right->left->right = new TreeNode(7);
  for (auto x : S.leftView(root))
    cout << x << " ";
  cout << endl;
  return 0;
}
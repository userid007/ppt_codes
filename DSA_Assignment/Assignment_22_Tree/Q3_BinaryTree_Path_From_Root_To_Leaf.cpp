// Given a binary tree, print all its root-to-leaf paths without using recursion.
// For example, consider the following Binary Tree.

//        6
//      /   \
//     3     5
//   /   \    \
//  2     5    4
//      /   \
//     7     4

// There are 4 leaves, hence 4 root to leaf paths -
//   6->3->2
//   6->3->5->7
//   6->3->5->4
//   6->5>4

#include <iostream>
#include <queue>
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
  void helper(TreeNode *root, string str, vector<string> &path)
  {
    if (root == nullptr)
      return;

    if (root->left == nullptr && root->right == nullptr)
    {
      path.push_back(str + to_string(root->val));
      return;
    }

    helper(root->left, str + to_string(root->val) + "->", path);
    helper(root->right, str + to_string(root->val) + "->", path);
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> path;
    helper(root, "", path);
    return path;
  }
};

int main()
{
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(3);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  Solution S;
  vector<string> ans = S.binaryTreePaths(root);
  for (auto str : ans)
    cout << str << endl;
  return 0;
}
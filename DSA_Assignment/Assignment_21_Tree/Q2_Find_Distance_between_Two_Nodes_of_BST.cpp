// Question 2:

// Given a Binary Search Tree with all unique values and two keys.
// Find the distance between two nodes in BST. The given keys always exist in BST.

// Example:

// Consider the following BST:
//                 8
//               /   \
//              3     10
//             / \      \
//            1   6     14
//               / \    /
//              4   7  13
// Input-1:
// n = 9
// values = [8, 3, 1, 6, 4, 7, 10, 14,13]
// node-1 = 6
// node-2 = 14

// Output-1:
// The distance between the two keys = 4

// Input-2:
// n = 9
// values = [8, 3, 1, 6, 4, 7, 10, 14,13]
// node-1 = 3
// node-2 = 4

// Output-2:
// The distance between the two keys = 2

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

class Solution
{
public:
  int distanceFromRoot(TreeNode *root, int x)
  {
    if (root->val == x)
      return 0;
    else if (root->val > x)
      return 1 + distanceFromRoot(root->left, x);
    else
      return 1 + distanceFromRoot(root->right, x);
  }

  int distanceBetweenNode(TreeNode *root, int a, int b)
  {
    if (root == nullptr)
      return 0;

    if (root->val > a && root->val > b)
      return distanceBetweenNode(root->left, a, b);
    else if (root->val < a && root->val < b)
      return distanceBetweenNode(root->right, a, b);
    else
      return distanceFromRoot(root, a) + distanceFromRoot(root, b);
  }
  int findDistWrapper(TreeNode *root, int a, int b)
  {
    if (a > b)
      swap(a, b);
    return distanceBetweenNode(root, a, b);
  }
};

int main()
{
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(3);
  root->right = new TreeNode(10);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(6);
  root->right->right = new TreeNode(14);
  root->left->right->left = new TreeNode(4);
  root->left->right->right = new TreeNode(7);
  root->right->right->left = new TreeNode(13);

  Solution S;
  cout << S.findDistWrapper(root, 6, 14) << endl;
  cout << S.findDistWrapper(root, 3, 4) << endl;

  return 0;
}
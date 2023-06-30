// Question 1
// Given a binary tree, task is to find subtree with maximum sum in tree.

// Examples:

// Input :       1
//             /   \
//            2      3
//           / \    / \
//          4   5  6   7
// Output : 28
// As all the tree elements are positive,
// the largest subtree sum is equal to
// sum of all tree elements.

// Input :       1
//             /    \
//           -2      3
//           / \    /  \
//          4   5  -6   2
// Output : 7
// Subtree with largest sum is :
//    -2
//    / \ 
//   4   5
// Also, entire tree sum is also 7.

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
  int findLargestSubTreeSumUtil(TreeNode *root, int &ans)
  {
    if (root == nullptr)
      return 0;

    int currSum =
        root->val +
        findLargestSubTreeSumUtil(root->left, ans) +
        findLargestSubTreeSumUtil(root->right, ans);

    ans = max(ans, currSum);
    return currSum;
  }

  int findLargestSubTreeSum(TreeNode *root)
  {
    if (root == nullptr)
      return 0;

    int ans = INT_MIN;
    findLargestSubTreeSumUtil(root, ans);
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(-1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  Solution S;
  cout << S.findLargestSubTreeSum(root) << endl;
  return 0;
}
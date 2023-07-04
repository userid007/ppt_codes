// Given Preorder, Inorder, and Postorder traversals of some tree. Write a program to check if they all are of the same tree.

// Examples:

// Input : Inorder -> 4 2 5 1 3
//         Preorder -> 1 2 4 5 3
//         Postorder -> 4 5 2 3 1
// Output : Yes
// Explanation : All of the above three traversals are of
// the same tree              1
//                          /   \
//                         2     3
//                       /   \
//                      4     5

// Input : Inorder -> 4 2 5 1 3
//         Preorder -> 1 5 4 2 3
//         Postorder -> 4 1 2 3 5
// Output : No
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
  TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int &rootIdx, int start, int end)
  {
    if (start > end)
      return nullptr;

    TreeNode *root = new TreeNode(preorder[rootIdx++]);
    int mid = find(inorder.begin() + start, inorder.begin() + end, root->val) - inorder.begin();

    root->left = buildTreeHelper(preorder, inorder, rootIdx, start, mid - 1);
    root->right = buildTreeHelper(preorder, inorder, rootIdx, mid + 1, end);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int rootIdx = 0;
    return buildTreeHelper(preorder, inorder, rootIdx, 0, inorder.size() - 1);
  }

  void helper(TreeNode *root, vector<int> &tree)
  {
    if (root == nullptr)
      return;
    helper(root->left, tree);
    helper(root->right, tree);
    tree.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> tree;
    helper(root, tree);
    return tree;
  }

  void sameTree(vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
  {
    TreeNode *root = buildTree(preorder, inorder);
    if (postorderTraversal(root) == postorder)
      cout << "True" << endl;
    else
      cout << "False" << endl;
  }
};

int main()
{
  vector<int> inorder = {4, 2, 5, 1, 3}, preorder = {1, 2, 4, 5, 3}, postorder = {4, 5, 2, 3, 1};

  Solution S;
  S.sameTree(preorder, inorder, postorder);

  inorder = {4, 2, 5, 1, 3}, preorder = {1, 5, 4, 2, 3}, postorder = {4, 1, 2, 3, 5};
  S.sameTree(preorder, inorder, postorder);

  return 0;
}
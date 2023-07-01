// Question 1
// You are given a binary tree.
// The binary tree is represented using the TreeNode class.
// Each TreeNode has an integer value and left and right children, represented using the TreeNode class itself.
// Convert this binary tree into a binary search tree.
// Examples

// Example 1
// Input:
//           10
//          /  \
//         2    7
//        / \
//       8   4
// Output:
//           8
//          /  \
//         4    10
//        / \
//       2   7

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
  TreeNode *constructBST(vector<TreeNode *> &nodes, int start, int end)
  {
    if (start > end)
      return nullptr;
    int mid = (start + end) / 2;
    TreeNode *root = nodes[mid];
    root->left = constructBST(nodes, start, mid - 1);
    root->right = constructBST(nodes, mid + 1, end);
    return root;
  }

  TreeNode *convertToBST(TreeNode *root)
  {
    vector<TreeNode *> inorder = inorderTraversal(root);
    sort(begin(inorder), end(inorder), [](const TreeNode *a, const TreeNode *b)
         { return a->val < b->val; });
    return constructBST(inorder, 0, inorder.size() - 1);
  }

  void inorderTraversalhelper(TreeNode *root, vector<TreeNode *> &ans)
  {
    if (root == nullptr)
      return;
    inorderTraversalhelper(root->left, ans);
    ans.push_back(root);
    inorderTraversalhelper(root->right, ans);
  }

  vector<TreeNode *> inorderTraversal(TreeNode *root)
  {
    vector<TreeNode *> ans;
    inorderTraversalhelper(root, ans);
    return ans;
  }
};

void printInorder(TreeNode *root)
{
  if (root == nullptr)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(30);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(20);
  root->right->right = new TreeNode(5);

  Solution S;
  TreeNode *bst = S.convertToBST(root);
  printInorder(bst);
  cout << endl;

  root = new TreeNode(10);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(8);
  root->left->right = new TreeNode(4);

  bst = S.convertToBST(root);
  printInorder(bst);
  cout << endl;
  return 0;
}
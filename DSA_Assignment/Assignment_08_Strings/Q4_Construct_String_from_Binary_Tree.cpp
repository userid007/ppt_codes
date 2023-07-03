// Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

// Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

// Example 1
// Input: root = [1,2,3,4]
// Output: "1(2(4))(3)"
// Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"

// Example 2:
// Input: root = [1,2,3,null,4]
// Output: "1(2()(4))(3)"
// Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

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
  void preorder(TreeNode *root, string &res)
  {
    if (root == NULL)
      return;
    res.append(to_string(root->val));
    if (root->left == NULL && root->right == NULL)
      return;
    res.append("(");
    preorder(root->left, res);
    res.append(")");
    if (root->right != NULL)
    {
      res.append("(");
      preorder(root->right, res);
      res.append(")");
    }
  }

  string tree2str(TreeNode *root)
  {
    string s = "";
    preorder(root, s);
    return s;
  }
};

int main()
{
  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(3);

  Solution S;
  cout << S.tree2str(root) << endl;
  return 0;
}
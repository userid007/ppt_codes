// Question 2
// Construct the BST (Binary Search Tree) from its given level order traversal.

// Examples:

// Input: arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}
// Output: BST:
//               7
//             /   \       
//            4    12
//           / \   /
//          3   6  8
//         /   /   \
//        1   5    10

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
  TreeNode *levelOrder(TreeNode *root, int val)
  {
    if (root == nullptr)
      return new TreeNode(val);

    if (val < root->val)
      root->left = levelOrder(root->left, val);
    else
      root->right = levelOrder(root->right, val);

    return root;
  }

  TreeNode *constructBSTfromLevelOrder(vector<int> arr)
  {
    if (arr.empty())
      return nullptr;

    TreeNode *root = nullptr;
    for (int i = 0; i < arr.size(); i++)
    {
      root = levelOrder(root, arr[i]);
    }
    return root;
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
};

int main()
{
  vector<int> arr = {7, 4, 12, 3, 6, 8, 1, 5, 10};

  Solution S;
  TreeNode *root = S.constructBSTfromLevelOrder(arr);
  cout << "Inorder Traversal : " << endl;
  for (auto x : S.inorderTraversal(root))
    cout << x << " ";
  cout << endl;
  return 0;
}
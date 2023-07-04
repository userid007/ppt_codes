// A Given a binary tree, the task is to flip the binary tree towards the right direction that is clockwise.
// See the below examples to see the transformation.

// In the flip operation, the leftmost node becomes the root of the flipped tree and
// its parent becomes its right child and the right sibling becomes its left child and the same should be done for all left most nodes recursively.
//
// Example 1
//            1               4
//          /   \            / \  
//         2     3    ==>   5   2
//        / \   / \            / \    
//       4   5 6   7          3   1
//                           / \      
//                          6   7
// Example 2
//          1                 2
//         / \               / \  
//        2   3             3   1
//           / \           / \    
//          4   5         4   5

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
  TreeNode *flipBinaryTree(TreeNode *root)
  {
    if (root == nullptr)
      return root;

    if (root->left == nullptr && root->right == nullptr)
      return root;

    TreeNode *flippedRoot = flipBinaryTree(root->left);

    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = nullptr;

    return flippedRoot;
  }

  void printLevelOrder(TreeNode *root)
  {
    if (root == nullptr)
      return;

    queue<TreeNode *> q;

    q.push(root);
    while (true)
    {
      int nodeCount = q.size();
      if (nodeCount == 0)
        break;

      while (nodeCount > 0)
      {
        TreeNode *node = q.front();
        cout << node->val << " ";
        q.pop();
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
        nodeCount--;
      }
      cout << endl;
    }
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  Solution S;
  S.printLevelOrder(root);
  cout << endl;
  root = S.flipBinaryTree(root);
  S.printLevelOrder(root);
  return 0;
}

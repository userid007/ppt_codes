// Given a Binary Tree, The task is to print the bottom view from left to right.
// A node x is there in output if x is the bottommost node at its horizontal distance.
// The horizontal distance of the left child of a node x is equal to a horizontal distance of x minus 1, and that of a right child is the horizontal distance of x plus 1.

// Examples:

// Input:            20
//                  /   \  
//                 8     22
//                / \     \  
//               5   3    25
//                  /  \      
//                10    14

// Output: 5, 10, 3, 14, 25.

// Input:              20
//                    /  \  
//                   8    22
//                  / \  /   \  
//                 5  3  4   25
//                   / \      
//                 10   14
// Output: 5 10 4 14 25.
// Explanation: If there are multiple bottom-most nodes for a horizontal distance from the root, then print the later one in the level traversal.
// 3 and 4 are both the bottom-most nodes at a horizontal distance of 0, we need to print 4.

#include <iostream>
#include <map>
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
  vector<int> bottomView(TreeNode *root)
  {
    vector<int> bottomV;
    if (root == nullptr)
      return bottomV;

    int hd = 0;

    map<int, int> mpp;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
      TreeNode *node = q.front().first;
      int line = q.front().second;
      q.pop();

      if (node != nullptr)
      {
        mpp[line] = node->val;
        q.push({node->left, line - 1});
        q.push({node->right, line + 1});
      }
    }

    for (auto it : mpp)
      bottomV.push_back(it.second);

    return bottomV;
  }
};

int main()
{
  TreeNode *root = new TreeNode(20);
  root->left = new TreeNode(8);
  root->right = new TreeNode(22);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(25);
  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(14);
  Solution S;
  for (auto x : S.bottomView(root))
    cout << x << " ";
  cout << endl;

  root = new TreeNode(20);
  root->left = new TreeNode(8);
  root->right = new TreeNode(22);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(25);
  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(14);
  for (auto x : S.bottomView(root))
    cout << x << " ";
  cout << endl;
  return 0;
}

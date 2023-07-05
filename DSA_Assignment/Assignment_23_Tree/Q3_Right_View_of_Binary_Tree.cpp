// Given a Binary Tree, print the Right view of it.
// The right view of a Binary Tree is a set of nodes visible when the tree is visited from the Right side.

// Examples:
// Input:
//          1
//       /     \
//     2         3
//   /   \      /  \
//  4     5    6    7
//              \
//                8

// Output:
// Right view of the tree is 1 3 7 8

// Input:
//          1
//        /
//      8
//    /
//   7

// Output:
// Right view of the tree is 1 8 7

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
  void rightViewUtil(TreeNode *root, vector<int> &rightV, int level, int *max_level)
  {
    if (root == nullptr)
      return;

    if (*max_level < level)
    {
      rightV.push_back(root->val);
      *max_level = level;
    }

    rightViewUtil(root->right, rightV, level + 1, max_level);
    rightViewUtil(root->left, rightV, level + 1, max_level);
  }

  vector<int> rightView(TreeNode *root)
  {
    vector<int> rightV;
    int max_level = 0;
    rightViewUtil(root, rightV, 1, &max_level);
    return rightV;
  }
};

int main()
{

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->left->right = new TreeNode(8);

  Solution S;
  for (auto x : S.rightView(root))
    cout << x << " ";
  cout << endl;

  root = new TreeNode(1);
  root->left = new TreeNode(8);
  root->left->left = new TreeNode(7);
  for (auto x : S.rightView(root))
    cout << x << " ";
  cout << endl;

  return 0;
}
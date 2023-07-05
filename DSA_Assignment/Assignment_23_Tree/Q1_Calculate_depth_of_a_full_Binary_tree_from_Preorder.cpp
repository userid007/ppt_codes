// Given preorder of a binary tree, calculate its depth(or height) [starting from depth 0].
// The preorder is given as a string with two possible characters.

// ‘l’ denotes the leaf
// ‘n’ denotes internal node
// The given tree can be seen as a full binary tree where every node has 0 or two children.
// The two children of a node can ‘n’ or ‘l’ or mix of both.

// Examples :

// Input  : nlnll
// Output : 2
// Explanation :

// Input  : nlnnlll
// Output : 3

#include <iostream>
using namespace std;

class Solution
{
public:
  int findDepthRec(string tree, int &index)
  {
    if (index >= tree.size() || tree[index] == 'l')
      return 0;

    index++;
    int left = findDepthRec(tree, index);

    index++;
    int right = findDepthRec(tree, index);

    return max(left, right) + 1;
  }

  int findDepth(string tree)
  {
    int index = 0;
    return findDepthRec(tree, index);
  }
};

int main()
{
  Solution S;
  cout << S.findDepth("nlnnlll") << endl;
  cout << S.findDepth("nlnll") << endl;
  return 0;
}

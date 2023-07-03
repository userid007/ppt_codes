// Question 3
// Given an array of size n. The problem is to check whether the given array can represent the level order traversal of a Binary Search Tree or not.

// Examples:

// Input : arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}
// Output : Yes
// For the given arr[] the Binary Search Tree is:
//          7
//        /   \       
//       4     12
//      / \    /
//     3   6  8
//    /   /    \
//   1   5     10

// Input : arr[] = {11, 6, 13, 5, 12, 10}
// Output : No
// The given arr[] do not represent the level
// order traversal of a BST.

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

struct NodeDetails
{
  int val;
  int min, max;
  NodeDetails() : val(0), min(INT_MIN), max(INT_MAX){};
  NodeDetails(int x) : val(x), min(INT_MIN), max(INT_MAX){};
  NodeDetails(int x, int min, int max) : val(x), min(min), max(max){};
};

class Solution
{
public:
  bool levelOrderIsOfBST(vector<int> arr)
  {
    if (arr.empty())
      return true;

    queue<NodeDetails> q;

    int i = 0;

    q.push(NodeDetails(arr[i++]));

    while (i != arr.size() && !q.empty())
    {
      NodeDetails curr = q.front();
      q.pop();

      if (i < arr.size() && (arr[i] < curr.val && arr[i] > curr.min))
        q.push(NodeDetails(arr[i++], curr.min, curr.val));

      if (i < arr.size() && (arr[i] > curr.val && arr[i] < curr.max))
        q.push(NodeDetails(arr[i++], curr.val, curr.max));
    }

    if (i == arr.size())
      return true;

    return false;
  }
};

int main()
{
  vector<int> arr = {7, 4, 12, 3, 6, 8, 1, 5, 10};

  Solution S;
  cout << S.levelOrderIsOfBST(arr) << endl;
  arr = {11, 6, 13, 5, 12, 10};
  cout << S.levelOrderIsOfBST(arr) << endl;
  return 0;
}
// **Question 7**
// You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

// Count and return the number of maximum integers in the matrix after performing all the operations

// **Example 1:**

// **Input:** m = 3, n = 3, ops = [[2,2],[3,3]]

// **Output:** 4

// **Explanation:** The maximum integer in M is 2, and there are four of it in M. So return 4.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // This ans might cause mle or tle
  int maxCountI(int m, int n, vector<vector<int>> &ops)
  {
    int count = 0;
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (auto op : ops)
      for (int idx = 0; idx < op[0]; idx++)
        for (int jdx = 0; jdx < op[1]; jdx++)
          ans[idx][jdx]++;

    for (auto row : ans)
      for (auto num : row)
        if (ans[0][0] == num)
          count++;

    return count;
  }

  int maxCountII(int m, int n, vector<vector<int>> &ops)
  {
    int x = m, y = n;
    for (auto op : ops)
    {
      x = min(x, op[0]);
      y = min(y, op[1]);
    }
    return x * y;
  }
};

int main()
{
  int m, n, k;
  cin >> m >> n >> k;
  vector<vector<int>> ops(k, vector<int>(2));
  for (int i = 0; i < k; i++)
    cin >> ops[i][0] >> ops[i][1];

  Solution S;
  cout << S.maxCountII(m, n, ops) << endl;
  return 0;
}
// Question 8
// Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2.
// You may assume that multiplication is always possible.

// Example:
// Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
// Output: [[7,0,0],[-7,0,3]]

// Example 2:
// Input: mat1 = [[0]], mat2 = [[0]]
// Output: [[0]]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B)
  {
    vector<vector<int>> ans(A.size(), vector<int>(B.size()));
    for (int i = 0; i < A.size(); i++)
    {
      for (int j = 0; j < B.size(); j++)
      {
        for (int k = 0; k < B[0].size(); k++)
        {
          ans[i][j] += A[i][k] * B[j][k];
        }
      }
    }

    return ans;
  }
};

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> A(m, vector<int>(n));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> A[i][j];
    }
  }

  cin >> m >> n;
  vector<vector<int>> B(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> B[i][j];
    }
  }
  Solution S;
  vector<vector<int>> ans = S.multiply(A, B);

  cout << "[";
  for (auto row : ans)
  {
    cout << "[";
    for (auto num : row)
    {
      cout << num << ',';
    }
    cout << "\b],";
  }
  cout << "\b]" << endl;
  return 0;
}
// **Question 3**
// Given a 2D integer array matrix, return *the **transpose** of* matrix.

// The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// **Example 1:**

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

// Output: [[1,4,7],[2,5,8],[3,6,9]]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> transpose(vector<vector<int>> &matrix)
  {
    int R = matrix.size(), C = matrix[0].size();
    vector<vector<int>> solution(C, vector<int>(R));

    for (int r = 0; r < R; r++)
    {
      for (int c = 0; c < C; c++)
      {
        solution[c][r] = matrix[r][c];
      }
    }
    return solution;
  }
};

int main()
{
  int m, n, input;
  cin >> m >> n;

  vector<vector<int>> arr(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  Solution S;
  vector<vector<int>> ans = S.transpose(arr);
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
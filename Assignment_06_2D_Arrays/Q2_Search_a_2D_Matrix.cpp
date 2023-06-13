// Question 2

// You are given an m x n integer matrix matrix with the following two properties:

// - Each row is sorted in non-decreasing order.
// - The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int rows = matrix.size(), cols = matrix[0].size(), row = 0, col = cols - 1;

    while (row < rows && col > -1)
    {
      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] > target)
        col--;
      else
        row++;
    }
    return false;
  }
};

int main()
{
  int m, n, target, input;
  cin >> m >> n >> target;

  vector<vector<int>> arr(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  Solution S;
  cout << S.searchMatrix(arr, target) << endl;
  return 0;
}
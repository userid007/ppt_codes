// Question 7

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    vector<vector<int>> ans(n, vector<int>(n));
    int up = 0, right = n - 1, left = 0, down = n - 1;
    int counter = 0;
    while (up <= down && left <= right)
    {
      for (int col = left; col <= right; ++col)
        ans[up][col] = ++counter;
      ++up;

      for (int row = up; row <= down; ++row)
        ans[row][right] = ++counter;
      --right;

      if (up <= down)
      {
        for (int col = right; col >= left; --col)
          ans[down][col] = ++counter;
        --down;
      }

      if (left <= right)
      {
        for (int row = down; row >= up; --row)
          ans[row][left] = ++counter;
        ++left;
      }
    }
    return ans;
  }
};

int main()
{
  int n;
  cin >> n;

  Solution S;
  vector<vector<int>> ans = S.generateMatrix(n);

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
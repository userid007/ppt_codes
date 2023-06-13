// Question 8

// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
// Check if these points make a straight line in the XY plane.

// Example 1:
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool checkStraightLine(vector<vector<int>> &coordinates)
  {
    int deltaX = coordinates[1][0] - coordinates[0][0];
    int deltaY = coordinates[1][1] - coordinates[0][1];

    for (int i = 2; i < coordinates.size(); i++)
    {
      if (deltaY * (coordinates[i][0] - coordinates[i - 1][0]) !=
          deltaX * (coordinates[i][1] - coordinates[i - 1][1]))
        return false;
    }
    return true;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> nums(n, vector<int>(2));
  Solution S;
  cout << S.checkStraightLine(nums) << endl;
  return 0;
}
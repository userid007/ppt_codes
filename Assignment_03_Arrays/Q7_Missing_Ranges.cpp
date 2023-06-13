// Question 7
// You are given an inclusive range [lower, upper] and a sorted unique integer array
// nums, where all elements are within the inclusive range.

// A number x is considered missing if x is in the range [lower, upper] and x is not in
// nums.

// Return the shortest sorted list of ranges that exactly covers all the missing
// numbers. That is, no element of nums is included in any of the ranges, and each
// missing number is covered by one of the ranges.

// Example 1:
// Input: nums = [0,1,3,50,75], lower = 0, upper = 99
// Output: [[2,2],[4,49],[51,74],[76,99]]

// Explanation: The ranges are:
// [2,2]
// [4,49]
// [51,74]
// [76,99]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper)
  {
    vector<vector<int>> ans;
    int i = lower, j = 0;
    while (j < nums.size())
    {
      if (i == nums[j])
      {
        i++, j++;
      }
      else
      {
        ans.push_back({i, nums[j] - 1});
        i = nums[j] + 1;
        j++;
      }
    }
    if (i <= upper)
      ans.push_back({i, upper});
    return ans;
  }
};

int main()
{
  vector<int> arr;
  int n, input, lower, upper;
  cin >> n >> lower >> upper;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
  }

  Solution s;
  vector<vector<int>> ans = s.findMissingRanges(arr, lower, upper);
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
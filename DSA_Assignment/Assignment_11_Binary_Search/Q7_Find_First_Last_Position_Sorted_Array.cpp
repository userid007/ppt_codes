// Question 7
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> ans(2, -1);
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target)
        left = mid + 1;
      else
      {
        if (nums[mid] == target)
          ans[0] = mid;
        right = mid - 1;
      }
    }

    left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target)
        right = mid - 1;
      else
      {
        if (nums[mid] == target)
          ans[1] = mid;
        left = mid + 1;
      }
    }

    return ans;
  }
};

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  Solution S;
  vector<int> ans = S.searchRange(nums, target);
  printf("[%d,%d]\n", ans[0], ans[1]);
  return 0;
}
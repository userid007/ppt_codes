// Question 1
// Given an integer array nums of length n and an integer target, find three integers
// in nums such that the sum is closest to the target.
// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2

// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right)
      {
        int current = nums[left] + nums[right] + nums[i];
        if (current == target)
          return current;
        if (abs(target - current) < abs(target - closest))
        {
          closest = current;
        }
        if (current > target)
          right--;
        else
          left++;
      }
    }
    return closest;
  }
};

int main()
{
  int n, input, target;
  cin >> n >> target;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
  }
  Solution s;
  cout << s.threeSumClosest(arr, target) << endl;
  return 0;
}
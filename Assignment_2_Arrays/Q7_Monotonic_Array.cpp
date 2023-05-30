// Question 7
// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
// monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isMonotonic(vector<int> &nums)
  {
    bool isIncreasing = true, isDecreasing = true;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] > nums[i + 1])
      {
        isDecreasing = false;
      }
      if (nums[i] < nums[i + 1])
      {
        isIncreasing = false;
      }
    }
    return isIncreasing || isDecreasing;
  }
};

int main()
{
  int n, input;
  vector<int> nums;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums.push_back(input);
  }

  Solution S;
  cout << S.isMonotonic(nums) << endl;
  return 0;
}
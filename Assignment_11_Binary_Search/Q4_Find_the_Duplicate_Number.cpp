// Question 4
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int left = 1, right = nums.size() - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      int c = 0;

      for (const int &num : nums)
        if (num <= mid)
          ++c;

      if (c > mid)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  Solution S;
  cout << S.findDuplicate(nums) << endl;

  return 0;
}
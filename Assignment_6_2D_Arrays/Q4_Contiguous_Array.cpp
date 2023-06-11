// Question 4

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findMaxLength(vector<int> &nums)
  {
    unordered_map<int, int> map = {{0, -1}};
    int sum = 0, maxLength = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i])
        ++sum;
      else
        --sum;

      if (map.find(sum) == map.end())
        map.insert({sum, i});
      else
        maxLength = max(maxLength, i - map[sum]);
    }
    return maxLength;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  Solution S;
  cout << S.findMaxLength(nums) << endl;
  return 0;
}
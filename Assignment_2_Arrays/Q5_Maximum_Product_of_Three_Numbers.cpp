// Question 5
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:
// Input: nums = [1,2,3]
// Output: 6

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  // it might cause TLE
  int maximumProductI(vector<int> &nums)
  {
    int mp = INT_MIN;
    for (int i = 0; i < nums.size() - 2; i++)
    {
      for (int j = i + 1; j < nums.size() - 1; j++)
      {
        for (int k = j + 1; k < nums.size(); k++)
        {
          mp = max(mp, nums[i] * nums[j] * nums[k]);
        }
      }
    }
    return mp;
  }

  int maximumProductII(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
  }

  int maximumProductIII(vector<int> &nums)
  {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for (int num : nums)
    {
      if (num <= min1)
      {
        min2 = min1;
        min1 = num;
      }
      else if (num <= min2)
      {
        min2 = num;
      }

      if (num >= max1)
      {
        max3 = max2;
        max2 = max1;
        max1 = num;
      }
      else if (num >= max2)
      {
        max3 = max2;
        max2 = num;
      }
      else if (num >= max3)
      {
        max3 = num;
      }
    }
    return max(min1 * min2 * max1, max1 * max2 * max3);
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
  cout << S.maximumProductIII(nums) << endl;
  return 0;
}
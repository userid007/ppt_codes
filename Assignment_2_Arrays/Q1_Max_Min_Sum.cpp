// **Question 1**
// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn)
// such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

// **Example 1:**
// Input: nums = [1,4,3,2]
// Output: 4

// **Explanation:** All possible pairings (ignoring the ordering of elements) are:

// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4 So the maximum possible sum is 4

#include <iostream>

using namespace std;

class Solution
{
public:
  int maxMinSum(vector<int> &nums)
  {
    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i * i < nums.size(); i++)
    {
      sum += min(nums[i], nums[nums.size() - i - 1]);
    }
    return sum;
  }
};

int main()
{
  vector<int> nums;
  int n, input;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums.push_back(input);
  }

  Solution S;
  cout << S.maxMinSum(nums) << endl;
  return 0;
}
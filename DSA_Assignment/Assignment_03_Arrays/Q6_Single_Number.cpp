// Question 6
// Given a non-empty array of integers nums, every element appears twice except
// for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      ans = ans ^ nums[i];
    }
    return ans;
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
  cout << S.singleNumber(nums) << endl;
  return 0;
}

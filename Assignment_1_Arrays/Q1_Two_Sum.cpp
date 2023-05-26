// **Q1.** Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// **Example:**
// Input: nums = [2,7,11,15], target = 9
// Output0 [0,1]

// **Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1]

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  // Here I have used map as we can't use sort: O(n)
  vector<int> twoSum(vector<int> &nums, int target)
  {
    map<int, int> numsMap;
    for (int i = 0; i < nums.size(); i++)
    {
      auto it = numsMap.find(target - nums[i]);
      if (it != numsMap.end())
        return {i, it->second};
      numsMap.insert({nums[i], i});
    }
    return {-1, -1};
  }
};

int main()
{
  vector<int> nums;
  int n, target, input;
  cin >> n >> target;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums.push_back(input);
  }

  Solution S;
  vector<int> ans = S.twoSum(nums, target);
  cout << "[" << ans[0] << "," << ans[1] << "]\n";
  return 0;
}
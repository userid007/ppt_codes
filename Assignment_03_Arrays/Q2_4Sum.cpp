// Question 2
// Given an array nums of n integers, return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that:
//            ● 0 <= a, b, c, d < n
//            ● a, b, c, and d are distinct.
//            ● nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
  }

  vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k)
  {
    vector<vector<int>> res;
    if (start == nums.size())
      return res;

    if (nums[start] > target / k || target / k > nums.back())
      return res;

    if (k == 2)
      return twoSum(nums, target, start);

    for (int i = start; i < nums.size(); ++i)
    {
      if (i == start || nums[i - 1] != nums[i])
      {
        for (vector<int> &subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1))
        {
          res.push_back({nums[i]});
          res.back().insert(end(res.back()), begin(subset), end(subset));
        }
      }
    }

    return res;
  }

  vector<vector<int>> twoSum(vector<int> &nums, long long target, int start)
  {
    vector<vector<int>> res;
    unordered_set<int> s;

    for (int i = start; i < nums.size(); ++i)
    {
      if (res.empty() || res.back()[1] != nums[i])
      {
        if (s.count(target - nums[i]))
        {
          res.push_back({int(target - nums[i]), nums[i]});
        }
      }
      s.insert(nums[i]);
    }
    return res;
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
  vector<vector<int>> ans = s.fourSum(arr, target);
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
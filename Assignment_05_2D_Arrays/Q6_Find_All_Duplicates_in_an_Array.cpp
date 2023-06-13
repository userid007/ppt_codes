// **Question 6**

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    vector<int> ans;
    for (int num : nums)
    {
      if (nums[abs(num) - 1] > 0){
        nums[abs(num) - 1] = -nums[abs(num) - 1];
      } else {
        ans.push_back(abs(num));
      }
    }
    return ans;
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
  vector<int> ans = S.findDuplicates(nums);
  cout << "[";
  for (auto x : ans)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
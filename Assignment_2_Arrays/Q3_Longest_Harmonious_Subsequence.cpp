// Question 3
// We define a harmonious array as an array where the difference between its maximum value
// and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence
// among all its possible subsequences.

// A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5

// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  int findLHS(vector<int> &nums)
  {
    int ans = 0;
    unordered_map<int, int> numsTable;
    for (int x : nums)
    {
      numsTable[x]++;
    }
    cout << numsTable.bucket(0);
    for (auto x : numsTable)
    {
      if (numsTable.find(x.first + 1) != numsTable.end())
      {
        cout << numsTable[x.first + 1] << endl;
        ans = max(ans, x.second + numsTable[(x.first + 1)]);
      }
    }
    return ans;
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
  cout << S.findLHS(nums) << endl;
  return 0;
}

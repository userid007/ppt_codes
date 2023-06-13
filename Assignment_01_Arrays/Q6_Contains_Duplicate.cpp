// **Q6.** Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// **Example 1:**
// Input: nums = [1,2,3,1]

// Output: true

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_map<int, int> m;
    for (auto x : nums)
    {
      if (m[x]++)
      {
        return true;
      }
    }
    return false;
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
  cout << S.containsDuplicate(nums) << endl;

  return 0;
}
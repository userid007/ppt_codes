// **Q7.** Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

// Note that you must do this in-place without making a copy of the array.

// **Example 1:**
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int i = 0;
    for (int num : nums)
    {
      if (num)
      {
        nums[i++] = num;
      }
    }
    while (i < nums.size())
    {
      nums[i++] = 0;
    }
  }

  // this solution is more optimized than above
  void moveZeroesII(vector<int> &nums)
  {
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
      {
        swap(nums[i], nums[count++]);
      }
    }
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
  S.moveZeroesII(nums);
  cout << "[";
  for (auto x : nums)
  {
    cout << x << ",";
  }
  cout << "\b]\n";

  return 0;
}
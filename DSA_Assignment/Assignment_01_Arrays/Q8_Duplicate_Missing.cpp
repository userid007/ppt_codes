// **Q8.** You have a set of integers s, which originally contains all the numbers from 1 to n.
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// **Example 1:**
// Input: nums = [1,2,2,4]
// Output: [2,3]

#include <iostream>

using namespace std;

class Solution
{
public:
  vector<int> duplicateMissing(vector<int> &nums)
  {
    for (int curr = 1; curr <= nums.size(); curr++)
    {
      if (nums[curr - 1] != curr)
      {
        return {nums[curr - 1], curr};
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
  vector<int> ans = S.duplicateMissing(nums);
  cout << "[";
  for (auto x : ans)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
// **Question 5**
// You are given a large integer represented as an integer array digits, where each
// digits[i] is the ith digit of the integer. The digits are ordered from most significant
// to least significant in left-to-right order. The large integer does not contain any
// leading 0's.

// Increment the large integer by one and return the resulting array of digits.

// **Example 1:**
// Input: digits = [1,2,3]
// Output: [1,2,4]

// **Explanation:** The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void incrementArray(vector<int> &nums)
  {
    int next = 0;
    int curr = 0;
    nums.back()++;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      curr = nums[i];
      nums[i] = (curr + next) % 10;
      next = (curr + next) / 10;
    }
    if (next != 0)
    {
      nums.insert(nums.begin(), next);
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
  S.incrementArray(nums);
  cout << "[";
  for (auto x : nums)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
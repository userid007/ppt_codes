// Question 8
// You are given an integer array nums and an integer k.

// In one operation, you can choose any index i where 0 <= i < nums.
// length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k].
// You can apply this operation at most once for each index i.

// The score of nums is the difference between the maximum and minimum elements in nums.
// Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

// Example 1:
// Input: nums = [1], k = 0
// Output: 0

// Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

#include <iostream>

using namespace std;

class Solution
{
public:
  int maximum_Score(vector<int> &nums, int k)
  {
    int max = *min_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());
    return max - min + (2 * k);
  }
};

int main()
{
  int n, input, k;
  vector<int> nums;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums.push_back(input);
  }

  Solution S;
  cout << S.maximum_Score(nums, k) << endl;
  return 0;
}
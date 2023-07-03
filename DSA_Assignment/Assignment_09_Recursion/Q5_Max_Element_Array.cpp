// Question 5

// Given an array of integers arr, the task is to find maximum element of that array using recursion.

// Example 1:
// Input: arr = {1, 4, 3, -5, -4, 8, 6};
// Output: 8

// Example 2:
// Input: arr = {1, 4, 45, 6, 10, -8};
// Output: 45

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxRec(vector<int> &nums, int n)
  {
    if (n == 1)
      return nums[0];
    return max(nums[n - 1], maxRec(nums, n - 1));
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
  cout << S.maxRec(nums, n) << endl;
  return 0;
}
// Question 8

// Given an array, find a product of all array elements.

// Example 1:
// Input  : arr[] = {1, 2, 3, 4, 5}
// Output : 120

// Example 2:
// Input  : arr[] = {1, 6, 3}
// Output : 18

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int productArray(vector<int> &nums, int n)
  {
    if (n == 1)
      return nums[0];
    return nums[n - 1] * productArray(nums, n - 1);
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
  cout << S.productArray(nums, n) << endl;
  return 0;
}
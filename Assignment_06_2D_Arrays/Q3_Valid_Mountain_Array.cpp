// Question 3

// Given an array of integers arr, return true if and only if it is a valid mountain array.

// Recall that arr is a mountain array if and only if:

// - arr.length >= 3
// - There exists some i with 0 < i < arr.length - 1 such that:
//   - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//   - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Example 1:
// Input: arr = [2,1]
// Output: false

// Example 2:
// Input: arr = [3,5,5]
// Output: false

// Example 3:
// Input: arr = [0,3,2,1]
// Output: true

#include <iostream>

using namespace std;

class Solution
{
public:
  bool validMountainArray(vector<int> &arr)
  {
    int i = 0, j = arr.size() - 1;

    while (i + 1 < arr.size() && arr[i] < arr[i + 1])
      i++;

    while (j > 0 && arr[j - 1] > arr[j])
      j--;

    return i > 0 && i == j && j < arr.size() - 1;
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
  cout << S.validMountainArray(nums);
  return 0;
}
// Question 6
// Given an array of integers nums which is sorted in ascending order, and an integer target,
// write a function to search target in nums. If target exists, then return its index. Otherwise,
// return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4

// Explanation: 9 exists in nums and its index is 4

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int binarySearch(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right)
    {
      mid = left + (right - left) / 2;
      if (nums[mid] > target)
      {
        right = mid - 1;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else
      {
        return mid;
      }
    }
    return -1;
  }
};

int main()
{
  int n, input, target;
  vector<int> nums;
  cin >> n >> target;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums.push_back(input);
  }

  Solution S;
  cout << S.binarySearch(nums, target) << endl;
  return 0;
}
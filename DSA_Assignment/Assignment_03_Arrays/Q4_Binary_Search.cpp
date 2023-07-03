// Question 4
// Given a sorted array of distinct integers and a target value, return the index if the
// target is found. If not, return the index where it would be if it were inserted in
// order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // Two pointer are used
  int binarySearch(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right)
    {
      // to avoid overflow issue occurs when (left+right) / 2
      mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return mid;
  }
};

int main()
{
  vector<int> nums;
  int n, target, input;
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
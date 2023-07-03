// Question 8
// Given two integer arrays nums1 and nums2, return an array of their intersection.
// Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    if (nums1.size() > nums2.size())
      swap(nums1, nums2);

    for (int num2 : nums2)
    {
      if (binarySearch(nums1, num2))
        ans.push_back(num2);
    }
    return ans;
  }

  int binarySearch(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right)
    {
      mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        nums.erase(nums.begin() + mid);
        return true;
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
    return false;
  }
};

int main()
{
  int n;

  cin >> n;
  vector<int> nums1(n);
  for (int i = 0; i < n; i++)
    cin >> nums1[i];

  cin >> n;
  vector<int> nums2(n);
  for (int i = 0; i < n; i++)
    cin >> nums2[i];

  Solution S;
  return 0;
}
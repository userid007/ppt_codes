// **Q5.** You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// **Example 1:**
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

// **Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    vector<int> nums1copy = nums1;
    for (int i = 0; i < m; i++)
    {
      nums1copy.push_back(nums1[i]);
    }
    int p1 = 0;
    int p2 = 0;
    for (int p = 0; p < m + n; p++)
    {
      if (p2 >= n || (p1 < m && nums1copy[p1] < nums2[p2]))
      {
        nums1[p] = nums1copy[p1++];
      }
      else
      {
        nums1[p] = nums2[p2++];
      }
    }
  }
};

int main()
{
  vector<int> nums1;
  vector<int> nums2;
  int m, n, input;
  cin >> m >> n;
  for (int i = 0; i < m; i++)
  {
    cin >> input;
    nums1.push_back(input);
  }
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums2.push_back(input);
    nums1.push_back(0);
  }

  Solution S;
  S.merge(nums1, m, nums2, n);
  cout << "[";
  for (auto x : nums1)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
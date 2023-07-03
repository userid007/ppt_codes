// **Question 4**

// Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

// - answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
// - answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

// **Note** that the integers in the lists may be returned in **any** order.

// **Example 1:**

// **Input:** nums1 = [1,2,3], nums2 = [2,4,6]

// **Output:** [[1,3],[4,6]]

// **Explanation:**

// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].

// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  vector<vector<int>> printUncommon(vector<int> &nums1, vector<int> &nums2)
  {
    vector<vector<int>> ans(2);
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
      if (nums1[i] < nums2[j])
      {
        ans[0].push_back(nums1[i]);
        ++i;
      }
      else if (nums1[i] > nums2[j])
      {
        ans[1].push_back(nums2[j]);
        ++j;
      }
      else
      {
        ++i, ++j;
      }
    }
    while (i < nums1[i])
    {
      ans[0].push_back(nums1[i++]);
    }
    while (j < nums2[j])
    {
      ans[1].push_back(nums2[j++]);
    }
    return ans;
  }
};

int main()
{
  vector<int> arr1, arr2;
  int n, m, input;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> input;
    arr1.push_back(input);
  }
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr2.push_back(input);
  }

  Solution s;
  vector<vector<int>> ans = s.printUncommon(arr1, arr2);
  cout << "[";
  for (auto row : ans)
  {
    cout << "[";
    for (auto num : row)
    {
      cout << num << ',';
    }
    cout << "\b],";
  }
  cout << "\b]" << endl;
  return 0;
}
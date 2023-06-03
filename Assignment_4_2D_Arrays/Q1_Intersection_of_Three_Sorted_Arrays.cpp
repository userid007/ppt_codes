// **Question 1**
// Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order,
// return a sorted array of **only** the integers that appeared in **all** three arrays.

// **Example 1:**

// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

// Output: [1,5]

// **Explanation:** Only 1 and 5 appeared in the three arrays.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> arraysIntersection(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
  {
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while (i < nums1.size() && j < nums2.size() && k < nums3.size())
    {
      if (nums1[i] == nums2[j] && nums2[j] == nums3[k])
      {
        ans.push_back(nums1[i]);
        ++i, ++j, ++k;
      }
      else
      {
        int max = std::max({nums1[i], nums2[j], nums3[k]});
        if (nums1[i] < max)
          ++i;
        if (nums2[j] < max)
          ++j;
        if (nums3[k] < max)
          ++k;
      }
    }
    return ans;
  }
};

int main()
{
  vector<int> nums1, nums2, nums3;
  int m, n, o, input;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> input;
    nums1.push_back(input);
  }
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums2.push_back(input);
  }
  cin >> o;
  for (int i = 0; i < o; i++)
  {
    cin >> input;
    nums3.push_back(input);
  }

  Solution S;
  vector<int> ans = S.arraysIntersection(nums1, nums2, nums3);
  cout << "[";
  for (auto x : ans)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
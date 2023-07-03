// **Q2.** Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
// - Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
//   The remaining elements of nums are not important as well as the size of nums.
// - Return k.

// **Example :**
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]

// **Explanation:** Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores)

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // Two pointer are used
  vector<int> removeAllVal(vector<int> &nums, int val)
  {
    int lo = 0, hi = nums.size() - 1;
    int k = 0;
    while (lo < hi)
    {
      if (nums[hi] == val)
      {
        hi--;
      }
      else if (nums[lo] == val)
      {
        swap(nums[hi], nums[lo]);
        lo++;
        k++;
      }
      else
      {
        lo++;
        hi--;
      }
    }
    cout << k << ", ";
    return nums;
  }
};

int main()
{
  vector<int> nums;
  int n, val, input;
  cin >> n >> val;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums.push_back(input);
  }

  Solution S;
  vector<int> ans = S.removeAllVal(nums, val);
  cout << "[";
  for (auto x : ans)
  {
    cout << x << ",";
  }
  cout << "\b]\n";

  return 0;
}
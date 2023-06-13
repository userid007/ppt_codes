// **Question 3**
// A permutation of an array of integers is an arrangement of its members into a
// sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].

// The next permutation of an array of integers is the next lexicographically greater
// permutation of its integer. More formally, if all the permutations of the array are
// sorted in one container according to their lexicographical order, then the next
// permutation of that array is the permutation that follows it in the sorted container.

// If such an arrangement is not possible, the array must be rearranged as the
// lowest possible order (i.e., sorted in ascending order).

// ● For example, the next permutation of arr = [1,2,3] is [1,3,2].
// ● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// ● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
// have a lexicographical larger rearrangement.

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// **Example 1:**
// Input: nums = [1,2,3]
// Output: [1,3,2]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void nextPermutationI(vector<int> &nums)
  {
    next_permutation(begin(nums), end(nums));
  }

  void nextPermutationII(vector<int> &nums)
  {
    int i = nums.size() - 1, k = nums.size() - 1;
    while (i > 0 && nums[i - 1] >= nums[i])
      i--;

    for (int j = i; j < k; j++, k--)
      swap(nums[j], nums[k]);

    if (i > 0)
    {
      k = i--;
      while (nums[k] <= nums[i])
        k++;
      swap(nums[i], nums[k]);
    }
  }
};

int main()
{
  int n, input;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
  }
  Solution s;
  s.nextPermutationII(arr);
  cout << "[";
  for (auto num : arr)
  {
    cout << num << ',';
  }
  cout << "\b]" << endl;
  return 0;
}
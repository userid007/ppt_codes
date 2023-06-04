// Question 8

// An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

// Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

// Example 1:

// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]
// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].
// Example 2:

// Input: changed = [6,3,0,1]
// Output: []
// Explanation: changed is not a doubled array.
// Example 3:

// Input: changed = [1]
// Output: []
// Explanation: changed is not a doubled array.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<int> findOriginalArray(vector<int> &changed)
  {
    vector<int> ans;
    unordered_map<int, int> map;
    sort(changed.begin(), changed.end());
    for (int num : changed)
      map[num]++;

    if (map[0] > 1)
    {
      map[0] /= 2;
      while (map[0]--)
        ans.push_back(0);
    }

    for (int num : changed)
    {
      if (map[num] && map[2 * num] && num != 0)
      {
        ans.push_back(num);
        map[num]--;
        map[num * 2]--;
      }

      if (ans.size() * 2 == changed.size())
        return ans;
    }
    return {};
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
  vector<int> ans = S.findOriginalArray(nums);
  cout << "[";
  for (auto x : ans)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
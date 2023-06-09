// Question 1

// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
// - s[i] == 'I' if perm[i] < perm[i + 1], and
// - s[i] == 'D' if perm[i] > perm[i + 1].
// Given a string s, reconstruct the permutation perm and return it.
// If there are multiple valid permutations perm, return any of them.

// Example 1:
// Input: s = "IDID"
// Output: [0,4,1,3,2]

// Example 2:
// Input: s = "III"
// Output: [0,1,2,3]

// Example 3:
// Input: s = "DDI"
// Output: [3,2,0,1]

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> diStringMatch(string s)
  {
    vector<int> ans(s.size() + 1);
    int left = 0, right = s.size();
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == 'I')
        ans[i] = left++;
      else
        ans[i] = right--;
    }
    ans[s.size()] = left;
    return ans;
  }
};

int main()
{
  string s;
  cin >> s;
  Solution S;
  vector<int> ans = S.diStringMatch(s);
  cout << "[";
  for (auto x : ans)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
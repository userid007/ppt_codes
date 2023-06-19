// Question 6
// Given two strings s and p, return an array of all the start indices of p's anagrams in s.
// You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:
// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // sliding window
  vector<int> findAnagrams(string s, string p)
  {
    if (s.size() < p.size())
      return {};

    vector<int> freq_p(26, 0);
    vector<int> window(26, 0);

    for (int i = 0; i < p.size(); i++)
    {
      freq_p[p[i] - 'a']++;
      window[s[i] - 'a']++;
    }

    vector<int> ans;
    if (freq_p == window)
      ans.push_back(0);

    for (int i = p.size(); i < s.size(); i++)
    {
      window[s[i - p.size()] - 'a']--;
      window[s[i] - 'a']++;

      if (freq_p == window)
        ans.push_back(i - p.size() + 1);
    }
    return ans;
  }
};

int main()
{
  string s, p;
  cin >> s >> p;

  Solution S;
  vector<int> ans = S.findAnagrams(s, p);
  for (int i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}
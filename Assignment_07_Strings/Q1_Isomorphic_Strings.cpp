// Question 1

// Given two strings s and t, *determine if they are isomorphic*.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for (int idx = 0; idx < s.size(); idx++)
    {
      if (mp1[s[idx]] && mp1[s[idx]] != t[idx])
        return false;
      if (mp2[t[idx]] && mp2[t[idx]] != s[idx])
        return false;
      mp1[s[idx]] = t[idx];
      mp2[t[idx]] = s[idx];
    }
    return true;
  }

  bool isIsomorphicII(string s, string t)
  {
    int m1[256] = {0};
    int m2[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
      if (m1[s[i]] != m2[t[i]])
        return false;
      m1[s[i]] = i + 1;
      m2[t[i]] = i + 1;
    }
    return true;
  }
};

int main()
{
  string str1, str2;
  cin >> str1 >> str2;

  Solution S;
  cout << S.isIsomorphic(str1, str2) << endl;
  return 0;
}
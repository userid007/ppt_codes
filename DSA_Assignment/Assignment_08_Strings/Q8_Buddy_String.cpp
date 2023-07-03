// Question 8
// Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

// For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

// Example 1:
// Input: s = "ab", goal = "ba"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

// Example 2:
// Input: s = "ab", goal = "ab"
// Output: false
// Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

// Example 3:
// Input: s = "aa", goal = "aa"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool buddyStrings(string s, string goal)
  {
    if (s.size() != goal.size())
      return false;

    if (s == goal)
    {
      vector<int> frequency(26, 0);
      for (auto &ch : s)
      {
        frequency[ch - 'a'] += 1;
        if (frequency[ch - 'a'] == 2)
          return true;
      }
      return false;
    }

    int firstIndex = -1;
    int secondIndex = -1;

    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] != goal[i])
      {
        if (firstIndex == -1)
          firstIndex = i;
        else if (secondIndex == -1)
          secondIndex = i;
        else
          return false;
      }
    }

    if (secondIndex == -1)
      return false;

    return s[firstIndex] == goal[secondIndex] && s[secondIndex] == goal[firstIndex];
  }
};

int main()
{
  string s, goal;
  cin >> s >> goal;

  Solution S;
  cout << S.buddyStrings(s, goal) << endl;
  return 0;
}
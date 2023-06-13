// Question 6
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.

// - For example, if s = "abcde", then it will be "bcdea" after one shift.

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
#include <iostream>
using namespace std;

class Solution
{
public:
  bool rotateString(string s, string goal)
  {
    if (s.size() != goal.size())
      return false;

    for (int i = 0; i < s.size(); ++i)
    {
      if (s == goal)
        return true;
      s = s.substr(1) + s[0];
    }
    return false;
  }

  bool rotateStringII(string s, string goal)
  {
    if (s.size() != goal.size())
      return false;

    s = s + s;

    for (int i = 0; i < s.size(); i++)
    {
      if (s.substr(i, goal.size()) == goal)
        return true;
    }
    return false;
  }
};

int main()
{
  string str, goal;
  cin >> str >> goal;

  Solution S;
  cout << S.rotateString(str, goal) << endl;
  return 0;
}
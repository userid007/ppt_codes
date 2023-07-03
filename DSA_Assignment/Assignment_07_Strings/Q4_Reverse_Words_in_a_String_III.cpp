// Question 4
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "God Ding"
// Output: "doG gniD"

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    int i = 0;
    while (i < s.size())
    {
      int j = i;
      while (s[i] != ' ' && i < s.size())
        ++i;
      reverse(s.begin() + j, s.begin() + i);
      ++i;
    }
    return s;
  }
};

int main()
{
  string str;
  getline(cin, str);

  Solution S;
  cout << S.reverseWords(str) << endl;
  return 0;
}
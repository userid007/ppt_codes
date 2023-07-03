// Question 5
// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
// If there are fewer than k characters left, reverse all of them.
// If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

// Example 1:

// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Example 2:

// Input: s = "abcd", k = 2
// Output: "bacd"

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  string reverseStr(string s, int k)
  {
    for (int i = 0; i < s.size(); i += 2 * k)
    {
      if (i + k > s.size())
        reverse(s.begin() + i, s.end());
      else
        reverse(s.begin() + i, s.begin() + i + k);
    }
    return s;
  }
};

int main()
{
  string str;
  int k;
  cin >> str >> k;

  Solution S;
  cout << S.reverseStr(str, k) << endl;
  return 0;
}
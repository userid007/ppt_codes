// Question 5
// We are given a string S, we need to find count of all contiguous substrings starting and ending with same character.

// Examples :
// Input  : S = "abcab"
// Output : 7
// There are 15 substrings of "abcab"
// a, ab, abc, abca, abcab, b, bc, bca
// bcab, c, ca, cab, a, ab, b
// Out of the above substrings, there
// are 7 substrings : a, abca, b, bcab,
// c, a and b.

// Input  : S = "aba"
// Output : 4
// The substrings are a, b, a and aba

// Most efficient C++ program to count all
// substrings with same first and last characters.
// Most efficient C++ program to count all
// substrings with same first and last characters.
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int countSubstring(string s)
  {
    int result = 0;
    int n = s.length();

    unordered_map<char, int> count;
    for (char ch : s)
      count[ch]++;

    for (auto c : count)
      result += c.second * (c.second + 1) / 2;

    return result;
  }
};

int main()
{
  string s;
  cin >> s;

  Solution S;
  cout << S.countSubstring(s) << endl;
  return 0;
}

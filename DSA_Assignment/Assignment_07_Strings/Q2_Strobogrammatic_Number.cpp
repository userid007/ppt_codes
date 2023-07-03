// Question 2
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Write a function to determine if a number is strobogrammatic. The number is represented as a string.

// Example 1:

// Input:  "69"
// Output: true
// Example 2:

// Input:  "88"
// Output: true
// Example 3:

// Input:  "962"
// Output: false

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool isStrobogrammatic(string s)
  {
    unordered_map<char, char> map = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    for (int i = 0; i < s.size() / 2; i++)
    {
      if (map[s[i]] != s[s.size() - 1 - i])
        return false;
    }
    return true;
  }
};

int main()
{
  string str;
  cin >> str;

  Solution S;
  cout << S.isStrobogrammatic(str) << endl;
  return 0;
}
// Question 2
// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// - Any right parenthesis ')' must have a corresponding left parenthesis '('.
// - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "(*)"
// Output: true

// Example 3:
// Input: s = "(*))"
// Output: true

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  // greedy solution
  bool checkValidString(string s)
  {
    int leftMin = 0, leftMax = 0;
    for (char ch : s)
    {
      if (ch == '(')
        ++leftMin, ++leftMax;
      else if (ch == ')')
        --leftMin, --leftMax;
      else
        --leftMin, ++leftMax;

      if (leftMax < 0)
        return false;
      // to handle string like (*)( and also we can never have less than 0 open left brackets.
      if (leftMin < 0)
        leftMin = 0;
    }
    return leftMin == 0;
  }
};

int main()
{
  string str;
  cin >> str;

  Solution S;
  cout << S.checkValidString(str) << endl;
  return 0;
}
// Questionn 7
// Given two strings s and t, return true if they are equal when both are typed into empty text editors.
// '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

#include <iostream>
using namespace std;

class Solution
{
public:
  bool backspaceCompare(string s, string t)
  {
    int i = s.size() - 1, j = t.size() - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0)
    {
      while (i >= 0)
      {
        if (s[i] == '#')
          skipS++, i--;
        else if (skipS > 0)
          skipS--, i--;
        else
          break;
      }

      while (j >= 0)
      {
        if (t[j] == '#')
          skipT++, j--;
        else if (skipT > 0)
          skipT--, j--;
        else
          break;
      }

      if (i >= 0 && j >= 0 && s[i] != t[j])
        return false;

      if ((i >= 0) != (j >= 0))
        return false;

      i--, j--;
    }
    return true;
  }
};

int main()
{
  string str1, str2;
  cin >> str1 >> str2;

  Solution S;
  cout << S.backspaceCompare(str1, str2) << endl;
  return 0;
}
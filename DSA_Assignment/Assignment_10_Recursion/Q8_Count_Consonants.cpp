// Question 8

// Given a string, count total number of consonants in it. A consonant is an English alphabet character that is not vowel (a, e, i, o and u). Examples of constants are b, c, d, f, and g.

// Examples :
// Input : abc de
// Output : 3
// There are three consonants b, c and d.

// Input : geeksforgeeks portal
// Output : 12

#include <iostream>

using namespace std;

class Solution
{
public:
  bool isConsonant(char ch)
  {
    ch = tolower(ch);
    if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') && ch >= 'a' && ch <= 'z')
      return true;
    return false;
  }

  int countConsonants(string str, int n)
  {
    if (n == 1)
      return isConsonant(str[0]);
    return countConsonants(str, n - 1) + isConsonant(str[n - 1]);
  }
};

int main()
{
  string str;
  getline(cin, str);

  Solution S;
  cout << S.countConsonants(str, str.size()) << endl;
  return 0;
}
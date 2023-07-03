// Question 4

// Given a string calculate length of the string using recursion.

// Examples:

// Input : str = "abcd"
// Output :4

// Input : str = "GEEKSFORGEEKS"
// Output :13

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int strLength(string str)
  {
    if (str == "")
      return 0;
    else
      return 1 + strLength(str.substr(1));
  }
};

int main()
{
  string n;
  cin >> n;

  Solution S;
  cout << S.strLength(n) << endl;
  return 0;
}
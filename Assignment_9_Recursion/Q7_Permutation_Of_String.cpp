// Question 7

// Given a string S, the task is to write a program to print all permutations of a given string.

// Example 1:
// Input:
// S = “ABC”
// Output:
// “ABC”, “ACB”, “BAC”, “BCA”, “CBA”, “CAB”

// Example 2:
// Input:
// S = “XY”
// Output:
// “XY”, “YX”

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void permuteString(string &str, int left, int right)
  {
    if (left == right)
      cout << str << endl;
    else
    {
      for (int i = left; i <= right; i++)
      {
        swap(str[left], str[i]);
        permuteString(str, left + 1, right);
        swap(str[left], str[i]);
      }
    }
  }
};

int main()
{
  string str;
  cin >> str;
  Solution S;
  S.permuteString(str, 0, str.size() - 1);
  return 0;
}
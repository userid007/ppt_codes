// Question 3
// Given a set represented as a string, write a recursive code to print all subsets of it. The subsets can be printed in any order.

// Examples:

// Input :  set = “abc”
// Output : { “”, “a”, “b”, “c”, “ab”, “ac”, “bc”, “abc”}

// Input : set = “abcd”
// Output : { “”, “a” ,”ab” ,”abc” ,”abcd”, “abd” ,”ac” ,”acd”, “ad” ,”b”, “bc” ,”bcd” ,”bd” ,”c” ,”cd” ,”d” }

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void powerSet(string str, int index = -1, string curr = "")
  {
    if (index == str.length())
      return;

    cout << curr << "\n";

    for (int i = index + 1; i < str.length(); i++)
    {
      curr += str[i];
      powerSet(str, i, curr);
      curr.erase(curr.size() - 1);
    }
    return;
  }
};

int main()
{
  string n;
  cin >> n;

  Solution S;
  S.powerSet(n);

  return 0;
}
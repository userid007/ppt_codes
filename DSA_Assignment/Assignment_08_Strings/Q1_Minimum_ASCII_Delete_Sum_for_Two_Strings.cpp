// Question 1
// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
// Example 2:

// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

#include <iostream>
using namespace std;

class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    vector<vector<int>> dp(s1.size() + 1, (vector<int>(s2.size() + 1, 0)));

    // filling up last row( s1, - )
    for (int i = dp.size() - 2; i >= 0; i--)
      dp[i][dp[0].size() - 1] += s1[i] + dp[i + 1][dp[0].size() - 1];

    // filling up last col ( s2, - )
    for (int j = dp[0].size() - 2; j >= 0; j--)
      dp[dp.size() - 1][j] += s2[j] + dp[dp.size() - 1][j + 1];

    for (int i = dp[0].size() - 2; i >= 0; i--)
    {
      for (int j = dp[0].size() - 2; j >= 0; j--)
      {
        // if chars are same we will take diagonal value
        if (s1[i] == s2[j])
          dp[i][j] = dp[i + 1][j + 1];
        else
          dp[i][j] = min(s1[i] + dp[i + 1][j], s2[j] + dp[i][j + 1]);
      }
    }
    return dp[0][0];
  }
};

int main()
{
  string str1, str2;
  cin >> str1 >> str2;

  Solution S;
  cout << S.minimumDeleteSum(str1, str2) << endl;
  return 0;
}
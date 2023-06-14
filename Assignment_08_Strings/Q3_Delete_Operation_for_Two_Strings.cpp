// Question 3
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

// Example 1:
// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

// Example 2:
// Input: word1 = "leetcode", word2 = "etco"
// Output: 4

#include <iostream>
using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int lcs = longestCommonSubsequence(word1, word2);
    return word1.size() - lcs + word2.size() - lcs;
  }

  int longestCommonSubsequence(string text1, string text2)
  {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, (0)));
    for (int i = dp.size() - 2; i >= 0; --i)
    {
      for (int j = dp[0].size() - 2; j >= 0; --j)
      {
        if (text1[i] == text2[j])
          dp[i][j] = 1 + dp[i + 1][j + 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
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
  cout << S.minDistance(str1, str2) << endl;
  return 0;
}
// Question 3
// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
// You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
// You must also not convert the inputs to integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  string addStrings(string num1, string num2)
  {
    string ans = "";
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0, currSum = 0;
    while (i >= 0 && j >= 0)
    {
      currSum = int(num1[i--]) + int(num2[j--]) - 96 + carry;
      carry = currSum / 10;
      ans.push_back(char(currSum % 10) + '0');
    }
    while (i >= 0)
    {
      currSum = int(num1[i--]) - 48 + carry;
      carry = currSum / 10;
      ans.push_back(char(currSum % 10) + '0');
    }
    while (j >= 0)
    {
      currSum = int(num2[j--]) - 48 + carry;
      carry = currSum / 10;
      ans.push_back(char(currSum % 10) + '0');
    }
    if (carry)
    {
      ans.push_back(char(carry) + '0');
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
};

int main()
{
  string str1, str2;
  cin >> str1 >> str2;

  Solution S;
  cout << S.addStrings(str1, str2) << endl;
  return 0;
}
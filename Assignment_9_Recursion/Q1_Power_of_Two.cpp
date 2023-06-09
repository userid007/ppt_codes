// Question 1

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    if (n <= 0)
      return false;
    if (n == 1)
      return true;
    return n % 2 == 0 && isPowerOfTwo(n / 2);
  }
};

int main()
{
  int n;
  cin >> n;
  Solution S;
  cout << S.isPowerOfTwo(n) << endl;
  return 0;
}
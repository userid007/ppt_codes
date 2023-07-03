// Question 3

// Given a positive integer, N. Find the factorial of N.

// Example 1:
// Input: N = 5
// Output: 120

// Example 2:
// Input: N = 4
// Output: 24

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int fatorial(int n)
  {
    if (n == 1 || n == 0)
      return 1;
    return n * fatorial(n - 1);
  }
};

int main()
{
  int n;
  cin >> n;
  Solution S;
  cout << S.fatorial(n) << endl;
  return 0;
}
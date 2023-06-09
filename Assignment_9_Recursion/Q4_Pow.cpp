// Question 4

// Given a number N and a power P, the task is to find the exponent of this number raised to the given power, i.e. N^P.

// Example 1 :
// Input: N = 5, P = 2
// Output: 25

// Example 2 :
// Input: N = 2, P = 5
// Output: 32

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  double myPow(double n, int p)
  {
    if (p == 0)
      return 1;
    if (p < 0)
      return 1 / myPow(n, -p);
    return n * myPow(n, p - 1);
  }
};

int main()
{
  int p;
  double n;
  cin >> n >> p;
  Solution S;
  cout << S.myPow(n, p) << endl;
  return 0;
}
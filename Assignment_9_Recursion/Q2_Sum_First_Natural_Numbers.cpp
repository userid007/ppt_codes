// Question 2

// Given a number n, find the sum of the first natural numbers.

// Example 1:
// Input: n = 3
// Output: 6

// Example 2:
// Input  : 5
// Output : 15

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int firstNaturalSum(int n)
  {
    if (n == 1)
      return 1;
    return n + firstNaturalSum(n - 1);
  }
};

int main()
{
  int n;
  cin >> n;
  Solution S;
  cout << S.firstNaturalSum(n) << endl;
  return 0;
}
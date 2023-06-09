// Question 6

// Given first term (a), common difference (d) and a integer N of the Arithmetic Progression series, the task is to find Nth term of the series.

// Example 1:

// Input : a = 2 d = 1 N = 5
// Output : 6
// The 5th term of the series is : 6

// Example 2:

// Input : a = 5 d = 2 N = 10
// Output : 23
// The 10th term of the series is : 23

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int Nth_AP(int a, int d, int N)
  {
    return a + (N - 1) * d;
  }
  int Nth_AP_rec(int a, int d, int N)
  {
    if (N == 1)
      return a;
    return d + Nth_AP_rec(a, d, N - 1);
  }
};

int main()
{
  int a, d, N;
  cin >> a >> d >> N;

  Solution S;
  cout << S.Nth_AP_rec(a, d, N) << endl;
  return 0;
}
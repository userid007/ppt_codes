// Question 2

// Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.
// If no small element present on the left print -1.

// Example 1:
// Input: n = 3
// a = {1, 6, 2}
// Output: -1 1 1
// Explaination: There is no number at the
// left of 1. Smaller number than 6 and 2 is 1.

// Example 2:
// Input: n = 6
// a = {1, 5, 0, 3, 4, 5}
// Output: -1 1 -1 0 3 4
// Explaination: Upto 3 it is easy to see
// the smaller numbers. But for 4 the smaller
// numbers are 1, 0 and 3. But among them 3
// is closest. Similary for 5 it is 4.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> leftSmaller(int n, int a[])
  {
    stack<int> s;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
      while (!s.empty() && s.top() >= a[i])
        s.pop();

      if (s.empty())
        res[i] = -1;
      else
        res[i] = s.top();

      s.push(a[i]);
    }
    return res;
  }
};

int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  Solution ob;
  vector<int> ans = ob.leftSmaller(n, a);
  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}

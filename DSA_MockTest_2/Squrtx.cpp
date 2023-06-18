#include <iostream>

using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x <= 1)
      return x;

    int left = 1, right = x, mid;
    while (left <= right)
    {
      mid = left + (right - left) / 2;
      if (mid == x / mid)
        return mid;
      else if (mid > x / mid)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return right;
  }
};

int main()
{
  int n;
  cin >> n;

  Solution S;
  cout << S.mySqrt(n) << endl;

  return 0;
}
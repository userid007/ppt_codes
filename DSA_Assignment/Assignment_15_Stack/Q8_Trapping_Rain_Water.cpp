// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
// In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    int trappedRain = 0;
    vector<int> leftMax(height.size(), 0), rightMax(height.size(), 0);
    for (int i = 1; i < height.size(); i++)
    {
      leftMax[i] = max(height[i - 1], leftMax[i - 1]);
      rightMax[height.size() - i - 1] = max(height[height.size() - i], rightMax[height.size() - i]);
    }

    for (int i = 0; i < height.size(); i++)
      trappedRain += max(min(leftMax[i], rightMax[i]) - height[i], 0);

    return trappedRain;
  }

  // two pointer approach
  int trapII(vector<int> &height)
  {
    int left = 0, right = height.size() - 1;
    int leftMax = height[left], rightMax = height[right];
    int trappedRain = 0;
    while (left < right)
    {
      if (leftMax <= rightMax)
      {
        leftMax = max(height[++left], leftMax);
        trappedRain += leftMax - height[left];
      }
      else
      {
        rightMax = max(height[--right], rightMax);
        trappedRain += rightMax - height[right];
      }
    }
    return trappedRain;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> height(n);

  for (int i = 0; i < n; i++)
    cin >> height[i];

  Solution S;
  cout << S.trap(height) << endl;
  cout << S.trapII(height) << endl;

  return 0;
}
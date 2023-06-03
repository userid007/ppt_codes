// **Question 8**

// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

// *Return the array in the form* [x1,y1,x2,y2,...,xn,yn].

// **Example 1:**

// **Input:** nums = [2,5,1,3,4,7], n = 3

// **Output:** [2,3,5,4,1,7]

// **Explanation:** Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> shuffle(vector<int> &nums, int n)
  {
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size() / 2; i++)
    {
      ans[2 * i] = nums[i];
      ans[2 * i + 1] = nums[n + i];
    }
    return ans;
  }
};

int main()
{
  int m, n;
  cin >> m >> n;
  vector<int> nums(m);
  for (int i = 0; i < m; i++)
  {
    cin >> nums[i];
  }
  Solution S;
  vector<int> ans = S.shuffle(nums, n);
  cout << "[";
  for (auto x : ans)
  {
    cout << x << ",";
  }
  cout << "\b]\n";
  return 0;
}
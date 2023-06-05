#include <iostream>
using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size();
    int start = 0, end = n - 1, mid = 0;
    while (mid <= end)
    {
      if (nums[mid] != 0)
      {
        swap(nums[start++], nums[mid]);
      }
      mid++;
    }
  }
};

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  Solution S;
  S.moveZeroes(nums);

  cout << "[";
  for (auto num : nums)
  {
    cout << num << ",";
  }
  cout << "\b]\n";
  return 0;
}
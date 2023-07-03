// Question 8
// Given an array of meeting time intervals where intervals[i] = [starti, endi],
// determine if a person could attend all meetings.

// Example 1:
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: false

#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
  int start;
  int end;
};

class Solution
{
public:
  bool canAttendMeetings(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); ++i)
    {
      if (intervals[i][0] < intervals[i - 1][1])
        return false;
    }
    return true;
  }
};

int main()
{
  vector<vector<int>> nums;
  Interval I;
  int n, input1, input2;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> input1 >> input2;
    nums.push_back({input1, input2});
  }
  Solution S;
  cout << S.canAttendMeetings(nums) << endl;
  return 0;
}

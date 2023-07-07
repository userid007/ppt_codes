// Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of every element in the array.

// Note: If there is no smaller element on right side or left side of any element then we take zero as the smaller element.
// For example for the leftmost element, the nearest smaller element on the left side is considered as 0.
// Similarly, for rightmost elements, the smaller element on the right side is considered as 0.

// Examples:

// Input : arr[] = {2, 1, 8}
// Output : 1
// Left smaller  LS[] {0, 0, 1}
// Right smaller RS[] {1, 0, 0}
// Maximum Diff of abs(LS[i] - RS[i]) = 1

// Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
// Output : 4
// Left smaller   LS[] = {0, 2, 4, 4, 4, 7, 2}
// Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
// Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4

// Input : arr[] = {5, 1, 9, 2, 5, 1, 7}
// Output : 1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  void leftSmaller(vector<int> &arr, vector<int> &SE)
  {
    stack<int> S;
    for (int i = 0; i < arr.size(); i++)
    {
      while (!S.empty() && S.top() >= arr[i])
        S.pop();

      if (!S.empty())
        SE[i] = S.top();

      else
        SE[i] = 0;

      S.push(arr[i]);
    }
  }

  int findMaxDiff(vector<int> &arr)
  {
    vector<int> LS(arr.size());
    leftSmaller(arr, LS);

    vector<int> RS(arr.size());
    reverse(arr.begin(), arr.end());
    leftSmaller(arr, RS);

    int result = -1;
    for (int i = 0; i < arr.size(); i++)
      result = max(result, abs(LS[i] - RS[arr.size() - 1 - i]));

    return result;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Solution S;
  cout << S.findMaxDiff(arr) << endl;
  return 0;
}

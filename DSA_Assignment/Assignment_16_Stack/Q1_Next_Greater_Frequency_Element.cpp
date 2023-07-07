// Given an array, for each element find the value of the nearest element to the right which is having a frequency greater than that of the current element.
// If there does not exist an answer for a position, then make the value ‘-1’.

// Examples:

// Input : a[] = [1, 1, 2, 3, 4, 2, 1]
// Output : [-1, -1, 1, 2, 2, 1, -1]

// Explanation:
// Given array a[] = [1, 1, 2, 3, 4, 2, 1]
// Frequency of each element is: 3, 3, 2, 1, 1, 2, 3

// Lets calls Next Greater Frequency element as NGF
// 1. For element a[0] = 1 which has a frequency = 3,
//    As it has frequency of 3 and no other next element
//    has frequency more than 3 so  '-1'
// 2. For element a[1] = 1 it will be -1 same logic
//    like a[0]
// 3. For element a[2] = 2 which has frequency = 2,
//    NGF element is 1 at position = 6  with frequency
//    of 3 > 2
// 4. For element a[3] = 3 which has frequency = 1,
//    NGF element is 2 at position = 5 with frequency
//    of 2 > 1
// 5. For element a[4] = 4 which has frequency = 1,
//    NGF element is 2 at position = 5 with frequency
//    of 2 > 1
// 6. For element a[5] = 2 which has frequency = 2,
//    NGF element is 1 at position = 6 with frequency
//    of 3 > 2
// 7. For element a[6] = 1 there is no element to its
//    right, hence -1

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterFrq(vector<int> arr)
  {
    stack<int> st;
    vector<int> ans(arr.size());
    unordered_map<int, int> freq;

    for (int x : arr)
      freq[x]++;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
      while (!st.empty() and freq[st.top()] <= freq[arr[i]])
        st.pop();

      if (st.empty())
        ans[i] = -1;
      else
        ans[i] = st.top();

      st.push(arr[i]);
    }
    return ans;
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
  for (int x : S.nextGreaterFrq(arr))
  {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
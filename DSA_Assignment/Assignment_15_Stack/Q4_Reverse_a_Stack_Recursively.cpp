// Question 4
// You are given a stack St. You have to reverse the stack using recursion.

// Example 1:

// Input:
// St = {3,2,1,7,6}
// Output:
// {6,7,1,2,3}
// Explanation:
// Input stack after reversing will look like the stack in the output.
// Example 2:

// Input:
// St = {4,3,9,6}
// Output:
// {6,9,3,4}
// Explanation:
// Input stack after reversing will look like the stack in the output.

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  void insert_at_bottom(stack<int> &st, int x)
  {
    if (st.empty())
      st.push(x);
    else
    {
      int curr = st.top();
      st.pop();
      insert_at_bottom(st, x);
      st.push(curr);
    }
  }
  void Reverse(stack<int> &st)
  {
    if (st.empty())
      return;
    int curr = st.top();
    st.pop();
    Reverse(st);
    insert_at_bottom(st, curr);
  }
};

int main()
{
  int N;
  cin >> N;
  stack<int> St;
  for (int i = 0; i < N; i++)
  {
    int x;
    cin >> x;
    St.push(x);
  }
  Solution ob;
  ob.Reverse(St);
  vector<int> res;
  while (St.size())
  {
    res.push_back(St.top());
    St.pop();
  }
  for (int i = res.size() - 1; i >= 0; i--)
  {
    cout << res[i] << " ";
  }

  cout << endl;
}

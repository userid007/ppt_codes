// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value.
// Operators will only include the basic arithmetic operators like *, /, + and -.

// Example 1:

// Input: S = "231*+9-"
// Output: -4
// Explanation:
// After solving the given expression,
// we have -4 as result.
// Example 2:

// Input: S = "123+*8-"
// Output: -3
// Explanation:
// After solving the given postfix
// expression, we have -3 as result.

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  int evaluatePostfix(string postfixEq)
  {
    stack<int> st;
    int val1, val2;
    for (char ch : postfixEq)
    {
      if (isdigit(ch))
        st.push(ch - '0');
      else
      {
        val1 = st.top(), st.pop();
        val2 = st.top(), st.pop();
        switch (ch)
        {
        case '+':
          st.push(val2 + val1);
          break;
        case '-':
          st.push(val2 - val1);
          break;
        case '*':
          st.push(val2 * val1);
          break;
        case '/':
          st.push(val2 / val1);
          break;
        }
      }
    }
    return st.top();
  }
};

int main()
{
  string postfixEq;
  cin >> postfixEq;
  Solution S;

  cout << S.evaluatePostfix(postfixEq) << endl;
  return 0;
}

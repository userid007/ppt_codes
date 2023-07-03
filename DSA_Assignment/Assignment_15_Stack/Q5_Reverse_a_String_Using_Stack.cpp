// You are given a string S, the task is to reverse the string using stack.

// Example 1:

// Input: S="GeeksforGeeks"
// Output: skeeGrofskeeG

#include <iostream>
#include <stack>
using namespace std;

char *reverse(char *S, int len)
{
  stack<char> st;
  for (int i = 0; i < len; i++)
    st.push(S[i]);

  for (int i = 0; i < len; i++)
  {
    S[i] = st.top();
    st.pop();
  }
  return S;
}

int main()
{

  char str[10000];
  cin >> str;
  long long int len = strlen(str);
  char *ch = reverse(str, len);
  for (int i = 0; i < len; i++)
  {
    cout << ch[i];
  }
  cout << endl;
  return 0;
}

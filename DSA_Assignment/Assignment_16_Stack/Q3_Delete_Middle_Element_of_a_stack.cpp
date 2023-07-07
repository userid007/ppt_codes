// Given a stack with push(), pop(), and empty() operations, The task is to delete the middle element of it without using any additional data structure.

// Input  : Stack[] = [1, 2, 3, 4, 5]
// Output : Stack[] = [1, 2, 4, 5]

// Input  : Stack[] = [1, 2, 3, 4, 5, 6]
// Output : Stack[] = [1, 2, 4, 5, 6]

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  void deleteMid_util(stack<char> &s, int sizeOfStack, int current)
  {
    if (current == sizeOfStack / 2)
    {
      s.pop();
      return;
    }

    int x = s.top();
    s.pop();
    current += 1;

    deleteMid_util(s, sizeOfStack, current);

    s.push(x);
  }

  void deleteMid(stack<char> &s, int sizeOfStack)
  {
    deleteMid_util(s, sizeOfStack, 0);
  }
};

int main()
{
  stack<char> st;

  st.push('1');
  st.push('2');
  st.push('3');
  st.push('4');
  st.push('5');
 

  Solution S;
  S.deleteMid(st, st.size());

  while (!st.empty())
  {
    char p = st.top();
    st.pop();
    cout << p << " ";
  }
  cout << endl;
  return 0;
}
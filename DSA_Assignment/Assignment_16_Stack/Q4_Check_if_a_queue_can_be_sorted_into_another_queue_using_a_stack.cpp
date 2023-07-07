// Given a Queue consisting of first n natural numbers (in random order).
// The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack.
// The operation allowed are:

// Push and pop elements from the stack
// Pop (Or Dequeue) from the given Queue.
// Push (Or Enqueue) in the another Queue.
// Examples :

// Input : Queue[] = { 5, 1, 2, 3, 4 }
// Output : Yes
// Pop the first element of the given Queue i.e 5.
// Push 5 into the stack.
// Now, pop all the elements of the given Queue and push them to
// second Queue.
// Now, pop element 5 in the stack and push it to the second Queue.

// Input : Queue[] = { 5, 1, 2, 6, 3, 4 }
// Output : No
// Push 5 to stack.
// Pop 1, 2 from given Queue and push it to another Queue.
// Pop 6 from given Queue and push to stack.
// Pop 3, 4 from given Queue and push to second Queue.
// Now, from using any of above operation, we cannot push 5
// into the second Queue because it is below the 6 in the stack.

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  bool checkSorted(queue<int> &q)
  {
    stack<int> st;
    int size = q.size();
    int expected = 1;
    int front;

    while (!q.empty())
    {
      front = q.front();
      q.pop();

      if (front == expected)
        expected++;
      else
      {
        if (st.empty())
          st.push(front);
        else if (!st.empty() && st.top() < front)
          return false;
        else
          st.push(front);
      }

      while (!st.empty() && st.top() == expected)
      {
        st.pop();
        expected++;
      }
    }

    if (expected - 1 == size && st.empty())
      return true;

    return false;
  }
};

int main()
{
  queue<int> q;
  q.push(5);
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  Solution S;
  S.checkSorted(q) ? cout << "Yes\n" : cout << "No\n";

  return 0;
}

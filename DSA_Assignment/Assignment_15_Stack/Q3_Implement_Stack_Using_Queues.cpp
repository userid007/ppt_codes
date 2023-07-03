// Question 3

// Implement a Stack using two queues q1 and q2.

// Example 1:

// Input:
// push(2)
// push(3)
// pop()
// push(4)
// pop()
// Output: 3 4
// Explanation:
// push(2)    the stack will be {2}
// push(3)    the stack will be {2 3}
// pop()      poped element will be 3,
//            the stack will be {2}
// push(4)    the stack will be {2 4}
// pop()      poped element will be 4

// Example 2:

// Input:
// pop()
// push(4)
// push(5)
// pop()
// Output: -1 5

#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
  MyStack() {}
  queue<int> que;
  queue<int> tque;

  void push(int x)
  {
    this->que.push(x);
  }

  int pop()
  {
    if (this->empty())
      return -1;
    while (this->que.size() > 1)
    {
      this->tque.push(this->que.front());
      this->que.pop();
    }

    int top = this->que.front();
    this->que.pop();
    while (!this->tque.empty())
    {
      this->que.push(this->tque.front());
      this->tque.pop();
    }
    return top;
  }

  int top()
  {
    while (this->que.size() > 1)
    {
      this->tque.push(this->que.front());
      this->que.pop();
    }

    int top = que.front();
    this->tque.push(this->que.front());
    this->que.pop();

    while (!this->tque.empty())
    {
      this->que.push(this->tque.front());
      this->tque.pop();
    }
    return top;
  }

  bool empty()
  {
    return this->que.empty();
  }
};

int main()
{
  MyStack s;
  s.push(2);
  s.push(3);
  cout << s.pop() << " ";
  s.push(4);
  cout << s.pop() << endl;
  return 0;
}
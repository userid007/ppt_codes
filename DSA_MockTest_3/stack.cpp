// Implement a stack using an array in JavaScript.
// Include the necessary methods such as push, pop, and isEmpty.

#include <iostream>
#define max 1000
using namespace std;

class Stack
{
  int top = -1;
  int s[max];

public:
  int isempty()
  {
    if (this->top == -1)
      return true;
    else
      return false;
  }

  int size()
  {
    return this->top + 1;
  }

  void push(int num)
  {
    if (this->top < max - 1)
      this->s[++this->top] = num;
    else
      cout << "Stack Overflow" << endl;
  }

  void pop()
  {
    if (this->isempty())
      cout << "Stack Underflow" << endl;
    else
      this->top--;
  }

  int peek()
  {
    if (this->isempty())
    {
      cout << "Stack is empty ";
      return 0;
    }
    else
      return this->s[this->top];
  }
};

int main()
{
  Stack S;
  cout << (S.isempty() ? "True" : "False") << endl;
  cout << S.peek() << endl;
  cout << S.size() << endl;
  S.pop();
  S.push(0);
  S.push(1);
  S.push(2);
  S.push(3);
  S.push(4);
  S.pop();
  cout << (S.isempty() ? "True" : "False") << endl;
  cout << S.peek() << endl;
  cout << S.size() << endl;
  return 0;
}
// Implement a queue using an array in JavaScript.
// Include the necessary methods such as enqueue, dequeue, and isEmpty.

#include <iostream>
#define max 1000
using namespace std;

class Queue
{
  int back = 0;
  int front = 0;
  int q[max];

public:
  int isempty()
  {
    if (this->back == this->front)
      return true;
    else
      return false;
  }

  int size()
  {
    if (isempty())
      return 0;
    return this->back - this->front;
  }

  void enqueue(int num)
  {
    if (this->back == max)
      cout << "Queue is full" << endl;
    else
      this->q[this->back++] = num;
  }

  void dequeue()
  {
    if (this->isempty())
      cout << "Queue is empty" << endl;
    else
    {
      for (int i = 0; i < this->back - 1; i++)
        this->q[i] = this->q[i + 1];
      this->back--;
    }
  }

  int peek()
  {
    if (this->isempty())
    {
      cout << "Queue is empty ";
      return 0;
    }
    else
      return this->q[this->front];
  }
};

int main()
{
  Queue Q;
  cout << (Q.isempty() ? "True" : "False") << endl;
  cout << Q.peek() << endl;
  cout << Q.size() << endl;
  Q.dequeue();
  Q.enqueue(0);
  Q.enqueue(1);
  Q.enqueue(2);
  Q.enqueue(3);
  Q.enqueue(4);
  Q.enqueue(5);
  cout << Q.peek() << endl;
  Q.dequeue();
  cout << (Q.isempty() ? "True" : "False") << endl;
  cout << Q.peek() << endl;
  cout << Q.size() << endl;
  return 0;
}
// Given an integer k and a queue of integers, The task is to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  queue<int> reverseFirstK(queue<int> &q, int k)
  {
    k = k % q.size();
    if (k == 0)
      return q;

    stack<int> st;
    for (int i = 0; i < k; i++)
      st.push(q.front()), q.pop();

    while (!st.empty())
      q.push(st.top()), st.pop();

    for (int i = 0; i < q.size() - k; i++)
      q.push(q.front()), q.pop();
    return q;
  }
};

int main()
{
  queue<int> queue;
  queue.push(10);
  queue.push(20);
  queue.push(30);
  queue.push(40);
  queue.push(50);
  queue.push(60);
  queue.push(70);
  queue.push(80);
  queue.push(90);
  queue.push(100);

  int k = 5;
  Solution S;
  queue = S.reverseFirstK(queue, k);

  // Printing queue
  while (!queue.empty())
  {
    cout << queue.front() << " ";
    queue.pop();
  }
  cout << endl;
  return 0;
}
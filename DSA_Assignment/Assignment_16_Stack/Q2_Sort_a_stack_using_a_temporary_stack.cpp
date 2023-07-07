// Given a stack of integers, sort it in ascending order using another temporary stack.

// Examples:

// Input : [34, 3, 31, 98, 92, 23]
// Output : [3, 23, 31, 34, 92, 98]

// Input : [3, 5, 1, 4, 2, 8]
// Output : [1, 2, 3, 4, 5, 8]

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  stack<int> sortStack(stack<int> &input)
  {
    stack<int> tempStack;
    while (!input.empty())
    {
      int temp = input.top();
      input.pop();

      while (!tempStack.empty() && tempStack.top() < temp)
      {
        input.push(tempStack.top());
        tempStack.pop();
      }
      tempStack.push(temp);
    }
    return tempStack;
  }
};

int main()
{
  stack<int> input;
  input.push(34);
  input.push(3);
  input.push(31);
  input.push(98);
  input.push(92);
  input.push(23);

  Solution S;
  stack<int> tmpStack = S.sortStack(input);

  while (!tmpStack.empty())
  {
    cout << tmpStack.top() << " ";
    tmpStack.pop();
  }
  cout << endl;
  return 0;
}
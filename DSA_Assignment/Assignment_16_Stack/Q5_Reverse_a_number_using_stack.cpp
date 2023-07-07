// Given a number , write a program to reverse this number using stack.

// Examples:

// Input : 365
// Output : 563

// Input : 6899
// Output : 9986

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  int reverse_number(int number)
  {
    stack<int> st;

    while (number != 0)
    {
      st.push(number % 10);
      number = number / 10;
    }

    int reverse = 0;
    for (int i = 1; !st.empty(); i *= 10)
    {
      reverse = reverse + st.top() * i;
      st.pop();
    }

    return reverse;
  }
};

int main()
{
  int number;
  cin >> number;

  Solution S;
  cout << S.reverse_number(number) << endl;
  return 0;
}

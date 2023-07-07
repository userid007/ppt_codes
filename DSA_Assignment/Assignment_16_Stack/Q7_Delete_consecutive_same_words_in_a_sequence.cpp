// Given a sequence of n strings, the task is to check if any two similar words come together and
// then destroy each other then print the number of words left in the sequence after this pairwise destruction.

// Examples:

// Input : ab aa aa bcd ab
// Output : 3
// As aa, aa destroys each other so,
// ab bcd ab is the new sequence.

// Input :  tom jerry jerry tom
// Output : 0

// As first both jerry will destroy each other.
// Then sequence will be tom, tom they will also destroy
// each other. So, the final sequence doesn’t contain any
// word.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int removeConsecutiveSame(vector<string> v)
  {
    stack<string> st;
    for (string str : v)
    {
      if (st.empty())
        st.push(str);
      else if (st.top() != str)
        st.push(str);
      else
        st.pop();
    }
    return st.size();
  }
};

int main()
{
  vector<string> v = {"tom", "jerry", "jerry", "tom"};
  Solution S;
  cout << S.removeConsecutiveSame(v) << endl;
  cout << S.removeConsecutiveSame({"ab", "aa", "aa", "bcd", "ab"}) << endl;

  return 0;
}
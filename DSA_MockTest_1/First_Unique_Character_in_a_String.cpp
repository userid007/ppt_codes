#include <iostream>
using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {
    int charList[26] = {0};
    for (auto ch : s)
    {
      charList[ch - 'a']++;
    }
    for (int idx = 0; idx < s.size(); idx++)
    {
      if (charList[s[idx] - 'a'] == 1)
        return idx;
    }
    return -1;
  }
};

int main()
{
  string s;
  cin >> s;
  Solution S;
  cout << S.firstUniqChar(s) << endl;
  return 0;
}
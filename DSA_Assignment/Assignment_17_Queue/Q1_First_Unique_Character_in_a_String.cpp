// Given a string s, find the first non-repeating character in it and return its index.
// If it does not exist, return -1.

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {
    queue<char> q;
    unordered_map<char, int> hm;
    for (int i = 0; i < s.length(); i++)
    {
      hm[s[i]]++;
      q.push(s[i]);
    }

    int ans = -1;
    while (!q.empty())
    {
      if (hm[q.front()] <= 1)
      {
        ans = s.size() - q.size();
        break;
      }
      q.pop();
    }

    return ans;
  }
};

int main()
{
  string str;
  cin >> str;
  Solution S;
  cout << S.firstUniqChar(str) << endl;
  return 0;
}
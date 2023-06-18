#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int currSum = 0;
    ListNode *ans;
    ListNode *t = new ListNode(0);
    ans = t;
    while (currSum || l1 || l2)
    {
      currSum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      t->next = new ListNode(currSum % 10);
      t = t->next;
      currSum /= 10;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    return ans->next;
  }
};

int main()
{
  ListNode *l1, *l2;

  l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution S;
  ListNode *ans = S.addTwoNumbers(l1, l2);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
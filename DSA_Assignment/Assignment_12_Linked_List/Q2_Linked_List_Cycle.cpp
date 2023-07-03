// Question 2
// Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// x(position at which tail is connected) = 2
// Output:True
// Explanation:In above test case N = 3.
// The linked list with nodes N = 3 is
// given. Then value of x=2 is given which
// means last node is connected with xth
// node of linked list. Therefore, there
// exists a loop.

// Example 2:
// Input:
// N = 4
// value[] = {1,8,3,4}
// x = 0
// Output:False
// Explanation:For N = 4 ,x = 0 means
// then lastNode->next = NULL, then
// the Linked list does not contains
// any loop.

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};

int main()
{
  struct ListNode *head = new ListNode(1);
  head->next = new ListNode(3);
  head->next->next = new ListNode(4);
  head->next->next->next = head->next->next;

  Solution S;
  cout << S.hasCycle(head) << endl;

  head = new ListNode(1);
  head->next = new ListNode(8);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  cout << S.hasCycle(head) << endl;

  return 0;
}
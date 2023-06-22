// Question 8
// Given a singly linked list, find if the linked list is circular or not.

// A linked list is called circular if it is not NULL-terminated and all nodes are connected in the form of a cycle.
// Below is an example of a circular linked list.

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
  bool isCircular(ListNode *head)
  {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return slow == head;
    }
    return false;
  }
};

int main()
{
  struct ListNode *head = new ListNode(1);
  head->next = new ListNode(3);
  head->next->next = new ListNode(4);
  head->next->next->next = head;

  Solution S;
  cout << S.isCircular(head) << endl;

  head = new ListNode(1);
  head->next = new ListNode(8);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  cout << S.isCircular(head) << endl;

  return 0;
}
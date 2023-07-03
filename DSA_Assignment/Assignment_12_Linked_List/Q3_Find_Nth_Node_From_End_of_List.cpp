// Question 3
// Given a linked list consisting of L nodes and given a number N.
// The task is to find the Nth node from the end of the linked list.

// Example 1:
// Input:
// N = 2
// LinkedList: 1->2->3->4->5->6->7->8->9
// Output:8
// Explanation:In the first example, there
// are 9 nodes in linked list and we need
// to find 2nd node from end. 2nd node
// from end is 8.

// Example 2:
// Input:
// N = 5
// LinkedList: 10->5->100->5
// Output:-1
// Explanation:In the second example, there
// are 4 nodes in the linked list and we
// need to find 5th from the end. Since 'n'
// is more than the number of nodes in the
// linked list, the output is -1.

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
  int findNthFromEnd(ListNode *head, int n)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < n - 1 && fast; i++)
      fast = fast->next;

    if (!fast)
      return -1;

    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow->val;
  }
};

int main()
{
  struct ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);
  head->next->next->next->next->next->next->next->next = new ListNode(9);

  Solution S;
  cout << S.findNthFromEnd(head, 2) << endl;

  head = new ListNode(10);
  head->next = new ListNode(5);
  head->next->next = new ListNode(100);
  head->next->next->next = new ListNode(5);

  cout << S.findNthFromEnd(head, 5) << endl;
  return 0;
}
// Question 1

// Given a singly linked list, delete middle of the linked list.
// For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
// If there are even nodes, then there would be two middle nodes, we need to delete the second middle element.
// For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
// If the input linked list is NULL or has 1 node, then it should return NULL

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5
// Output:1 2 4 5

// Example 2:
// Input:
// LinkedList: 2->4->6->7->5->1
// Output:2 4 6 5 1

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
  ListNode *deleteMiddle(ListNode *head)
  {
    if (head->next == nullptr)
      return nullptr;

    ListNode *slow = head, *fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
  }
};

int main()
{
  int n;
  cin >> n;

  struct ListNode *head, *temp;

  cin >> head->val;
  temp = head;
  for (int i = 1; i < n; i++)
  {
    cin >> temp->val;
    temp = temp->next;
  }

  Solution S;
  head = S.deleteMiddle(head);
  while (head != NULL)
  {
    cout << head->val;
    head = head->next;
  }
  return 0;
}
// Question 4

// Given a singly linked list of characters, write a function that returns true if the given list is a palindrome, else false.

// Examples:
// Input: R-A-D-A-R-NULL
// Output: Yes
// Input: C-O-D-E-NULL
// Output: No

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
  bool isPalindrome(ListNode *head)
  {
    // find the middle
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // reverse the second half
    ListNode *prev = slow;
    slow = slow->next;
    prev->next = NULL;
    while (slow)
    {
      ListNode *next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    slow = prev;

    while (slow && head)
    {
      if (head->val != slow->val)
        return false;
      head = head->next;
      slow = slow->next;
    }
    return true;
  }
};

int main()
{
  struct ListNode *head = new ListNode('R');
  head->next = new ListNode('A');
  head->next->next = new ListNode('D');
  head->next->next->next = new ListNode('A');
  head->next->next->next->next = new ListNode('R');

  Solution S;
  cout << S.isPalindrome(head) << endl;

  head = new ListNode('C');
  head->next = new ListNode('O');
  head->next->next = new ListNode('D');
  head->next->next->next = new ListNode('E');

  cout << S.isPalindrome(head) << endl;
  return 0;
}
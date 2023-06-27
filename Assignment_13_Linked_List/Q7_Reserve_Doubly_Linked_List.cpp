// Question 7
// Given a Doubly Linked List, the task is to reverse the given Doubly Linked List.

// Example:
// Original Linked list 10 8 4 2
// Reversed Linked list 2 4 8 10

#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode *prev;
  ListNode() : val(0), next(nullptr), prev(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
  ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class Solution
{
public:
  void reverseDoubly(ListNode **head)
  {
    ListNode *temp = nullptr, *current = *head;

    while (current != nullptr)
    {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;

      current = current->prev;
    }

    if (temp != nullptr)
      *head = temp->prev;
  }
};

ListNode *createDoublyLinkedList(vector<int> arr)
{
  struct ListNode *head = nullptr, *temp = nullptr;
  for (int i = 0; i < arr.size(); i++)
  {
    if (head == nullptr)
      head = new ListNode(arr[i]);
    else if (temp == nullptr)
    {
      temp = new ListNode(arr[i]);
      temp->prev = head;
      head->next = temp;
    }
    else
    {
      temp->next = new ListNode(arr[i]);
      temp->next->prev = temp;
      temp = temp->next;
    }
  }
  return head;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  struct ListNode *head = createDoublyLinkedList(arr);

  Solution S;
  S.reverseDoubly(&head);
  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  return 0;
}
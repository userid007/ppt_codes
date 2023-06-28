// Question 8

// Given a doubly linked list and a position.
// The task is to delete a node from given position in a doubly linked list.

// Example 1:

// Input:
// LinkedList = 1 <--> 3 <--> 4
// x = 3
// Output:1 3
// Explanation:After deleting the node at
// position 3 (position starts from 1),
// the linked list will be now as 1->3.

// Example 2:

// Input:
// LinkedList = 1 <--> 5 <--> 2 <--> 9
// x = 1
// Output:5 2 9

#include <iostream>
#include <vector>

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
  ListNode *deleteNodeAtGivenPos(ListNode *head, int pos)
  {
    ListNode *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
      temp = temp->next;
    }
    if (head == temp)
    {
      head = head->next;
      head->prev = nullptr;
    }
    else
    {
      temp->prev->next = temp->next;
      if (temp->next)
      {
        temp->next->prev = temp;
      }
    }
    return head;
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
  int n, pos;
  cin >> n >> pos;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  struct ListNode *head = createDoublyLinkedList(arr);

  Solution S;
  ListNode *ans = S.deleteNodeAtGivenPos(head, pos);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
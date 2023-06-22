// Question 6
// Given a linked list and two integers M and N.
// Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till end of the linked list.

// Difficulty Level: Rookie

// Example
// Input:
// M = 2, N = 2
// Linked List: 1->2->3->4->5->6->7->8
// Output:
// Linked List: 1->2->5->6

// Input:
// M = 3, N = 2
// Linked List: 1->2->3->4->5->6->7->8->9->10
// Output:
// Linked List: 1->2->3->6->7->8

// Input:
// M = 1, N = 1
// Linked List: 1->2->3->4->5->6->7->8->9->10
// Output:
// Linked List: 1->3->5->7->9

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
  ListNode *deleteNodes(ListNode *head, int m, int n)
  {
    int counter = m - 1;
    struct ListNode *temp = head;

    while (temp != nullptr)
    {
      while (counter-- && temp != nullptr)
        temp = temp->next;

      counter = n;
      while (counter-- && temp != nullptr && temp->next != nullptr)
        temp->next = temp->next->next;

      counter = m;
    }
    return head;
  }
};

ListNode *createLinkedList(vector<int> arr)
{
  struct ListNode *head = nullptr, *temp = nullptr;
  for (int i = 0; i < arr.size(); i++)
  {
    if (head == nullptr)
      head = new ListNode(arr[i]);
    else if (temp == nullptr)
    {
      temp = new ListNode(arr[i]);
      head->next = temp;
    }
    else
    {
      temp->next = new ListNode(arr[i]);
      temp = temp->next;
    }
  }
  return head;
}

int main()
{
  int n, M, N;
  cin >> n >> M >> N;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  struct ListNode *head = createLinkedList(arr);
  Solution S;

  head = S.deleteNodes(head, M, N);
  while (head != nullptr)
  {
    cout << head->val << endl;
    head = head->next;
  }
  return 0;
}
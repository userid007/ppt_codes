// Question 5

// Given a linked list and a key to be deleted.
// Delete last occurrence of key from linked.
// The list may have duplicates.

// Examples:
// ```
// Input:   1->2->3->5->2->10, key = 2
// Output:  1->2->3->5->10
// ```

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
  void deleteLast(ListNode **head, int k)
  {
    ListNode **lastKey = nullptr;

    while (*head)
    {
      if ((*head)->val == k)
        lastKey = head;
      head = &(*head)->next;
    }

    if (*lastKey)
    {
      ListNode *temp = *lastKey;
      *lastKey = temp->next;
      free(temp);
    }
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
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  struct ListNode *head = createLinkedList(arr);

  Solution S;
  S.deleteLast(&head, k);
  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  return 0;
}
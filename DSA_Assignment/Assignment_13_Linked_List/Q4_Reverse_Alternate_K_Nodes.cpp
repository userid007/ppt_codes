// Question 4
// Given a linked list, write a function to reverse every alternate k nodes (where k is an input to the function) in an efficient way.
// Give the complexity of your algorithm.

// Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
// Output:   3->2->1->4->5->6->9->8->7->NULL.

#include <iostream>
#include <vector>
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
  ListNode *kAltReverse(ListNode *head, int k)
  {
    ListNode *current = head, *next, *prev = nullptr;

    for (int i = 0; current != nullptr && i < k; i++)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    if (head != NULL)
      head->next = current;

    for (int i = 0; current != nullptr && i < k - 1; i++)
      current = current->next;

    if (current != NULL)
      current->next = kAltReverse(current->next, k);

    return prev;
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
  struct ListNode *ans = S.kAltReverse(head, k);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
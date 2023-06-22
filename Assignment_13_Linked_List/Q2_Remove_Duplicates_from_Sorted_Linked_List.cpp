// Question 2

// Write a function that takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list.
// The list should only be traversed once.

// For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates() should convert the list to 11->21->43->60.

// Example 1:

// Input:
// LinkedList:
// 11->11->11->21->43->43->60
// Output:
// 11->21->43->60

// Example 2:
// Input:
// LinkedList:
// 10->12->12->25->25->25->34
// Output:
// 10->12->25->34

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
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *curr = head;
    while (curr && curr->next)
    {
      if (curr->val == curr->next->val)
        curr->next = curr->next->next;
      else
        curr = curr->next;
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
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  struct ListNode *head = createLinkedList(arr);

  Solution S;
  struct ListNode *ans = S.deleteDuplicates(head);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
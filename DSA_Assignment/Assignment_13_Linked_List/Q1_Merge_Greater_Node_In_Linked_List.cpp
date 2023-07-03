// Question 1
// Given two linked list of the same size, the task is to create a new linked list using those linked lists.
// The condition is that the greater node among both linked list will be added to the new linked list.

// Examples
// Input: list1 = 5->2->3->8
// list2 = 1->7->4->5
// Output: New list = 5->7->4->8

// Input:list1 = 2->8->9->3
// list2 = 5->3->6->4
// Output: New list = 5->8->9->4

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
  ListNode *mergeAlternatively(ListNode *list1, ListNode *list2)
  {
    struct ListNode *ans = nullptr, *temp = nullptr;
    while (list1 && list2)
    {
      int currVal = max(list1->val, list2->val);
      if (ans == nullptr)
        ans = new ListNode(currVal);
      else if (temp == nullptr)
      {
        temp = new ListNode(currVal);
        ans->next = temp;
      }
      else
      {
        temp->next = new ListNode(currVal);
        temp = temp->next;
      }
      list1 = list1->next;
      list2 = list2->next;
    }
    return ans;
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
  struct ListNode *head1 = createLinkedList(arr);

  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  struct ListNode *head2 = createLinkedList(arr);

  Solution S;
  struct ListNode *ans = S.mergeAlternatively(head1, head2);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
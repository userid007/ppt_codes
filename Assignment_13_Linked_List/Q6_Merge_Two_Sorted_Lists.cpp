// Question 6

// Given two sorted linked lists consisting of N and M nodes respectively.
// The task is to merge both of the lists (in place) and return the head of the merged list.

// Examples:

// Input: a: 5->10->15, b: 2->3->20
// Output: 2->3->5->10->15->20

// Input: a: 1->1, b: 2->4
// Output: 1->1->2->4

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (list1 == NULL)
      return list2;
    if (list2 == NULL)
      return list1;

    if (list1->val <= list2->val)
    {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
    else
    {
      list2->next = mergeTwoLists(list2->next, list1);
      return list2;
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
  struct ListNode *ans = S.mergeTwoLists(head1, head2);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
// Question 7

// Given two linked lists, insert nodes of second list into first list at alternate positions of first list.
// For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty.
// The nodes of second list should only be inserted when there are positions available.
// For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.

// Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion must be done in-place.
// Expected time complexity is O(n) where n is number of nodes in first list.

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
  void mergeAlternatively(ListNode *list1, ListNode **list2)
  {
    struct ListNode *curr1 = list1, *curr2 = *list2, *next1, *next2;

    while (curr1 != nullptr && curr2 != nullptr)
    {
      next1 = curr1->next;
      next2 = curr2->next;

      curr2->next = next1;
      curr1->next = curr2;

      curr1 = next1;
      curr2 = next2;
    }
    *list2 = curr2;
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
  S.mergeAlternatively(head1, &head2);
  while (head1 != nullptr)
  {
    cout << head1->val << " ";
    head1 = head1->next;
  }
  cout << endl;

  while (head2 != nullptr)
  {
    cout << head2->val << " ";
    head2 = head2->next;
  }
  cout << endl;

  return 0;
}
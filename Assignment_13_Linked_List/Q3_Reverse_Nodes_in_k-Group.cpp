// Question 3

// Given a linked list of size N.
// The task is to reverse every k nodes (where k is an input to the function) in the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

// Example 1:
// Input:
// LinkedList: 1->2->2->4->5->6->7->8
// K = 4
// Output:4 2 2 1 8 7 6 5
// Explanation:
// The first 4 elements 1,2,2,4 are reversed first
// and then the next 4 elements 5,6,7,8. Hence, the
// resultant linked list is 4->2->2->1->8->7->6->5.

// Example 2:
// Input:
// LinkedList: 1->2->3->4->5
// K = 3
// Output:3 2 1 5 4
// Explanation:
// The first 3 elements are 1,2,3 are reversed
// first and then elements 4,5 are reversed.Hence,
// the resultant linked list is 3->2->1->5->4.

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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    struct ListNode *cursor = head;

    for (int i = 0; i < k; i++)
    {
      if (cursor == nullptr)
        return head;

      cursor = cursor->next;
    }
    ListNode *curr = head, *prev = nullptr, *next = nullptr;
    for (int i = 0; i < k; i++)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head->next = reverseKGroup(curr, k);
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
  struct ListNode *ans = S.reverseKGroup(head, k);
  while (ans != nullptr)
  {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  return 0;
}
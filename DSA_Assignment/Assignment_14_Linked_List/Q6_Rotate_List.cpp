// Given a singly linked list of size prefixNprefix.
// The task is to prefixleft-shiftprefix the linked list by prefixkprefix nodes,
// where prefixkprefix is a given positive integer smaller than or equal to length of the linked list.

// Example 1:

// Input:
// N = 5
// value[] = {2, 4, 7, 8, 9}
// k = 3
// Output:8 9 2 4 7
// Explanation:Rotate 1:4 -> 7 -> 8 -> 9 -> 2
// Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
// Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

// Example 2:
// Input:
// N = 8
// value[] = {1, 2, 3, 4, 5, 6, 7, 8}
// k = 4
// Output: 5 6 7 8 1 2 3 4

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
  ListNode *rotateRight(ListNode *head, int k)
  {
    // to handle edge cases first
    if (head == nullptr || head->next == nullptr || k == 0)
      return head;

    // to get length of link list and tail
    int length = 1;
    ListNode *tail = head;
    while (tail->next)
    {
      ++length;
      tail = tail->next;
    }

    k = k % length;
    if (k == 0)
      return head;

    ListNode *newLast = head;
    for (int i = 0; i < length - k - 1; i++)
      newLast = newLast->next;

    ListNode *newHead = newLast->next;
    newLast->next = nullptr;
    tail->next = head;
    return newHead;
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

void printList(ListNode *node)
{
  while (node != nullptr)
  {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
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
  printList(S.rotateRight(head, k));
  return 0;
}
// Given the head of a singly linked list,
// group all the nodes with odd indices together followed by the nodes with even indices,
// and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]

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
  ListNode *oddEvenList(ListNode *head)
  {
    if (head == nullptr)
      return head;
    ListNode *odd = head, *even = head->next, *evenHead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
      odd->next = even->next;
      odd = odd->next;

      even->next = odd->next;
      even = even->next;
    }
    odd->next = evenHead;
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
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  struct ListNode *head = createLinkedList(arr);

  Solution S;
  printList(S.oddEvenList(head));
  return 0;
}
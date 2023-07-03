// Question 2

// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Example 1:

// Input:
// LinkedList: 4->5->6
// Output:457

// Example 2:

// Input:
// LinkedList: 1->2->3
// Output:124

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
  int addOne(ListNode *head)
  {
    int ans = 0;
    while (head)
    {
      ans = ans * 10 + head->val;
      head = head->next;
    }
    return ans + 1;
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
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  struct ListNode *head = createLinkedList(arr);

  Solution S;
  cout << S.addOne(head) << endl;
  return 0;
}
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.

// (Note that in the examples below, all sequences are serializations of ListNode objects.)

// Example 1:

// Input: head = [1,2,-3,3,1]
// Output: [3,1]
// Note: The answer [1,2,1] would also be accepted.
// Example 2:

// Input: head = [1,2,3,-3,4]
// Output: [1,2,4]
// Example 3:

// Input: head = [1,2,3,-3,-2]
// Output: [1]

#include <iostream>
#include <unordered_map>

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
  ListNode *removeZeroSumSublists(ListNode *head)
  {
    ListNode *dummy = new ListNode();
    int prefix = 0;
    dummy->next = head;

    unordered_map<int, ListNode *> hm = {{prefix, dummy}};
    while (head)
    {
      prefix += head->val;
      if (hm.find(prefix) != hm.end())
      {
        ListNode *to_remove = hm[prefix]->next;
        int sum = prefix;
        while (to_remove != head)
        {
          sum += to_remove->val;
          hm.erase(sum);
          to_remove = to_remove->next;
        }
        hm[prefix]->next = head->next;
      }
      else
        hm[prefix] = head;
      head = head->next;
    }
    return dummy->next;
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
  Solution S;
  printList(S.removeZeroSumSublists(createLinkedList(arr)));
  return 0;
}
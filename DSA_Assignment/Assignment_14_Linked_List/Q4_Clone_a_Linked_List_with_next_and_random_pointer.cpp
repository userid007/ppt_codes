// You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b (arb is pointer to random node).

// Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.arb --> Y, then for the corresponding two nodes x and y in the copied list, x.arb --> y.

// Return the head of the copied linked list.

// ArbitLinked List1

// Note :- The diagram isn't part of any example, it just depicts an example of how the linked list may look like.

// Example 1:

// Input:
// N = 4, M = 2
// value = {1,2,3,4}
// pairs = {{1,2},{2,4}}
// Output: 1
// Explanation: In this test case, there
// are 4 nodes in linked list.  Among these
// 4 nodes,  2 nodes have arbitrary pointer
// set, rest two nodes have arbitrary pointer
// as NULL. Second line tells us the value
// of four nodes. The third line gives the
// information about arbitrary pointers.
// The first node arbitrary pointer is set to
// node 2.  The second node arbitrary pointer
// is set to node 4.
// Example 2:

// Input:
// N = 4, M = 2
// value[] = {1,3,5,9}
// pairs[] = {{1,1},{3,4}}
// Output: 1
// Explanation: In the given testcase ,
// applying the method as stated in the
// above example, the output will be 1.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode *arb;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), arb(nullptr) {}
  ListNode(int x, ListNode *next, ListNode *arb) : val(x), next(next), arb(arb) {}
};

class Solution
{
public:
  map<ListNode *, ListNode *> mp;
  ListNode *cloneLinkedList(ListNode *head)
  {
    if (!head)
    {
      return nullptr;
    }
    ListNode *node = new ListNode(head->val);
    mp[head] = node;
    node->next = cloneLinkedList(head->next);
    node->arb = mp[head->arb];

    return node;
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
  cout << node->val << "(" << node->arb->val << ")";
  node = node->next;
  while (node != nullptr)
  {
    cout << " -> " << node->val << "(" << node->arb->val << ")";
    node = node->next;
  }
  cout << endl;
}

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->arb = head->next->next;
  head->next->arb = head;
  head->next->next->arb = head->next->next->next->next;
  head->next->next->next->arb = head->next->next;
  head->next->next->next->next->arb = head->next;

  Solution S;
  printList(S.cloneLinkedList(head));
  return 0;
}
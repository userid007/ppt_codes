// Question 3

// Given a Linked List of size N,
// where every node represents a sub-linked-list and contains two pointers:
//   (i) a next pointer to the next node,
//   (ii) a bottom pointer to a linked list where this node is head.
//   Each of the sub-linked-list is in sorted order.
//   Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// Example 1:

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     |
// 7     20    22   35
// |           |     |
// 8          50    40
// |                 |
// 30               45
// Output: 5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Explanation:
// The resultant linked lists has every
// node in a single level.(Note:| represents the bottom pointer.)

// Example 2:

// Input:
// 5 -> 10 -> 19 -> 28
// |          |
// 7          22
// |          |
// 8          50
// |
// 30
// Output: 5->7->8->10->19->22->28->30->50
// Explanation:
// The resultant linked lists has every
// node in a single level.

#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next, *bottom;
  ListNode() : val(0), next(nullptr), bottom(nullptr) {}
  ListNode(int x) : val(x), next(nullptr), bottom(nullptr) {}
  ListNode(int x, ListNode *next, ListNode *bottom) : val(x), next(next), bottom(bottom) {}
};

struct mycomp
{
  bool operator()(ListNode *a, ListNode *b)
  {
    return a->val > b->val;
  }
};

class Solution
{
public:
  void flatten(ListNode *root)
  {
    priority_queue<ListNode *, vector<ListNode *>, mycomp> p;

    while (root != nullptr)
    {
      p.push(root);
      root = root->next;
    }

    while (!p.empty())
    {
      auto k = p.top();
      p.pop();

      cout << k->val << " ";
      if (k->bottom)
        p.push(k->bottom);
    }
  }
};

ListNode *push(ListNode *head_ref, int data)
{

  ListNode *new_node = new ListNode();
  new_node->val = data;
  new_node->next = nullptr;
  new_node->bottom = head_ref;
  head_ref = new_node;
  return head_ref;
}
int main()
{
  ListNode *head = new ListNode(5);
  auto temp = head;
  auto bt = head;
  bt->bottom = new ListNode(7);
  bt->bottom->bottom = new ListNode(8);
  bt->bottom->bottom->bottom = new ListNode(30);
  temp->next = new ListNode(10);

  temp = temp->next;
  bt = temp;
  bt->bottom = new ListNode(20);
  temp->next = new ListNode(19);
  temp = temp->next;
  bt = temp;
  bt->bottom = new ListNode(22);
  bt->bottom->bottom = new ListNode(50);
  temp->next = new ListNode(28);
  temp = temp->next;
  bt = temp;
  bt->bottom = new ListNode(35);
  bt->bottom->bottom = new ListNode(40);
  bt->bottom->bottom->bottom = new ListNode(45);
  Solution S;
  S.flatten(head);

  return 0;
}
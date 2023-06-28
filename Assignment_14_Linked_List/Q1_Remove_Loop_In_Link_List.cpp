// Question 1
// Given a linked list of N nodes such that it may contain a loop.

// A loop here means that the last node of the link list is connected to the node at position X(1-based index).
// If the link list does not have any loop, X=0.

// Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

// Example 1
// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output:1
// Explanation:The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|
// A loop is present. If you remove it
// successfully, the answer will be 1.

// Example 2
// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output:1
// Explanation:The Linked list does not
// contains any loop.

// Example 3
// Input:
// N = 4
// value[] = {1,2,3,4}
// X = 1
// Output:1
// Explanation:The link list looks like
// 1 -> 2 -> 3 -> 4
// ^              |
// |______________|
// A loop is present.
// If you remove it successfully,
// the answer will be 1.

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node() : data(0), next(nullptr) {}
  Node(int x) : data(x), next(nullptr) {}
  Node(int x, Node *next) : data(x), next(next) {}
};

void removeLoop(struct Node *loop_node, struct Node *head)
{
  struct Node *ptr1 = loop_node;
  struct Node *ptr2 = loop_node;

  unsigned int k = 1, i;
  while (ptr1->next != ptr2)
  {
    ptr1 = ptr1->next;
    k++;
  }

  ptr1 = head;

  ptr2 = head;
  for (i = 0; i < k; i++)
    ptr2 = ptr2->next;

  while (ptr2 != ptr1)
  {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  while (ptr2->next != ptr1)
    ptr2 = ptr2->next;

  ptr2->next = NULL;
}

int detectAndRemoveLoop(struct Node *list)
{
  struct Node *slow = list, *fast = list;

  while (slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      removeLoop(slow, list);
      return 1;
    }
  }

  return 0;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
}

int main()
{
  struct Node *head = new Node(50);
  head->next = new Node(20);
  head->next->next = new Node(15);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(10);

  /* Create a loop for testing */
  head->next->next->next->next->next = head->next->next;

  detectAndRemoveLoop(head);

  cout << "Linked List after removing loop \n";
  printList(head);
  return 0;
}

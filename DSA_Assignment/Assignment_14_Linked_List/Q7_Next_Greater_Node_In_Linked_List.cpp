// You are given the head of a linked list with n nodes.

// For each node in the list, find the value of the next greater node.
// That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

// Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed).
// If the ith node does not have a next greater node, set answer[i] = 0.

// Example 1:
// Input: head = [2,1,5]
// Output: [5,5,0]

// Example 2:
// Input: head = [2,7,4,3,5]
// Output: [7,0,5,5,0]

#include <iostream>
#include <stack>
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
  vector<int> nextLargerNodes(ListNode *head)
  {
    vector<int> answer;
    stack<pair<int, int>> stk;
    int cnt = 0;

    while (head != nullptr)
    {
      answer.push_back(0);
      while (stk.size() && head->val > stk.top().second)
      {
        answer[stk.top().first] = head->val;
        stk.pop();
      }

      stk.push({cnt++, head->val});
      head = head->next;
    }
    return answer;
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

void printVector(vector<int> ans)
{
  for (int x : ans)
    cout << x << " ";
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
  printVector(S.nextLargerNodes(head));
  return 0;
}
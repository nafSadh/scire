#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/**
* Definition for singly-linked list.*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
 public:
  ListNode *rotateRight(ListNode* head, int k)
  {
    int i = 0;
    if (head == nullptr) return head;
    ListNode *fwp = head;
    while (i++<k) {
      if (fwp->next == nullptr) {
        k = k%i;
        fwp = head;
        i = 0;
      } else {
        fwp = fwp->next;
      }
    }
    if (fwp == nullptr) return head;
    ListNode* swap = head;
    while (fwp->next != nullptr) {
      fwp = fwp->next;
      swap = swap->next;
    }

    fwp->next = head;
    head = swap->next;
    swap->next = nullptr;
    return head;
  }
};

void trav(ListNode* node)
{
  while (node != nullptr) {
    cout << node->val << ' ';
    node = node->next;
  }
  cout << endl;
}

ListNode* pushFront(ListNode* head, int val)
{
  ListNode *node = new ListNode(val);
  node->next= head;

  return node;
}

int main()
{
  ListNode* x = nullptr;
  for (int i = 3; i > 0; i--) {
    x = pushFront(x, i);
  }

  trav(x);
  Solution s;
  x = s.rotateRight(x, 5);
  trav(x);
  return 0;
}
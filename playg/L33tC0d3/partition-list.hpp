/*
Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two
partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

namespace L33tC0d3
{
  namespace partition_list
  {
    /** Definition for singly-linked list.*/
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution
    {
     public:
      ListNode *partition(ListNode *head, int x)
      {
        ListNode *newhd = nullptr;
        ListNode *leftend = nullptr;
        ListNode *rgthd = nullptr;
        ListNode *rightnd = nullptr;

        ListNode *node = head;

        while (node != nullptr) {
          ListNode *nxt = node->next;
          if (node->val<x) {
            if (newhd == nullptr) {
              newhd = node;
              leftend = node;
            } else {
              leftend->next = node;
              leftend = leftend->next;
            }
          } else {
            if (rgthd == nullptr) {
              rgthd = node;
              rightnd = node;
            } else {
              rightnd->next = node;
              rightnd = rightnd->next;
            }
          }
          node = nxt;
        }
        if (rightnd != nullptr)rightnd->next = nullptr;
        if (leftend != nullptr)leftend->next = rgthd;
        if (newhd == nullptr)newhd = rgthd;
        head = newhd;

        return newhd;
      }
    };
  }
}
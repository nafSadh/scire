/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

namespace L33tC0d3
{
  namespace rotate_linked_list
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
  }
}
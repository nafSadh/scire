/* Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. */

namespace L33tC0d3
{
  namespace remove_dups_from_sorted_list
  {
    // Definition for singly-linked list.
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution
    {
     public:
      ListNode *deleteDuplicates(ListNode *head)
      {
        ListNode* node = head;

        while (node != nullptr) {
          bool fwd = true;
          if (node->next != nullptr) {
            if (node->next->val == node->val) {
              ListNode *del = node->next;
              node->next = del->next;
              delete del;
              fwd = false;
            }
          }
          if (fwd) node = node->next;
        }

        return head;
      }
    };
  }
}
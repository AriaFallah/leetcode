// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto dummy = ListNode(0);
    ListNode* newList = &dummy;
    auto l1_p = l1;
    auto l2_p = l2;
    while (true) {
      if (l1_p && l2_p) {
        if (l1_p->val < l2_p->val) {
          newList->next = l1_p;  
          l1_p = l1_p->next;
        }
        else {
          newList->next = l2_p;
          l2_p = l2_p->next;
        }
        newList = newList->next;
      } else {
        if (l1_p) newList->next = l1_p;
        if (l2_p) newList->next = l2_p;
        break;
      }
    }
    return dummy.next;
  }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    if (head->val == head->next->val) {
      head->next = head->next->next;
      deleteDuplicates(head);
    } else {
      deleteDuplicates(head->next);
    }
    return head;
  }
};

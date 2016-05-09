// https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head) return false;
    auto hare = head;
    auto tortoise = head;
    while (hare && hare->next != 0) {
      hare = hare->next->next;
      tortoise = tortoise->next;
      if (tortoise == hare) return true;
    }
    return false;
  }
};

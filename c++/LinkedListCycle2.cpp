// https://leetcode.com/problems/linked-list-cycle-ii/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
  ListNode* detectCycle(ListNode *head) {
    if (!head || head->next == 0) return 0;
    auto hare = head;
    auto tortoise = head;

    while (hare && hare->next != 0) {
      hare = hare->next->next;
      tortoise = tortoise->next;
      if (tortoise == hare) break;
    }

    // Make sure it broke out because of a cycle
    if (tortoise != hare) return 0;

    tortoise = head;
    while (tortoise != hare) {
      hare = hare->next;
      tortoise = tortoise->next;
    }

    return hare;
  }
};

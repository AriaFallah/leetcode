// https://leetcode.com/problems/odd-even-linked-list/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

#include <utility>

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return 0;
    auto even = head->next;
    auto even_front = even;
    auto odd = head;
    while (even && even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = even->next->next;
      even = even->next;
    }
    odd->next = even_front;
    return head;
  }
};

// This was a result of misreading the instructions but is still pretty cool
// It'll split the list into odd and even without maintaining order, but
// it doesn't need the order of the list to be odd/even/odd/even/odd/even
class Solution2 {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return 0;
    auto front = head;
    while (true) {
      while (front && front->val % 2 == 1) front = front->next;
      if (!front || !front->next) return head;
      auto current = front->next;
      while (current && current->val % 2 == 0) current = current->next;
      if (!current) return head;
      std::swap(front->val, current->val);
    }
    return head;
  }
};

// https://leetcode.com/problems/delete-node-in-a-linked-list/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
  void deleteNode(ListNode* node) {
    if (node == 0) return;
    if (node->next == 0) {
      delete node;
      node = 0;
      return;
    };
    ListNode* next = node->next;
    *node = *next;
    delete next;
  }
};

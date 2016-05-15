// https://leetcode.com/problems/remove-linked-list-elements/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

#include <stack>

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    std::stack<ListNode*> stack;

    auto current = head;
    while (current) {
      if (current->val != val) stack.push(current);
      current = current->next;
    }

    ListNode* newList = 0;
    while (!stack.empty()) {
      ListNode* node = stack.top(); stack.pop();
      node->next = newList;
      newList = node;
    }

    return newList;
  }
};

// https://leetcode.com/problems/reverse-linked-list/

// Reverse a singly linked list.

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;

    ListNode* temp = nullptr;
    ListNode* previous = head;
    ListNode* current = head->next;
    previous->next = nullptr;

    while (current) {
      temp = current;
      current = current->next;
      temp->next = previous;
      previous = temp;
    }

    return previous;
  }
};

// https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>

class Queue {
public:
  Queue(): _q() {}

  // Push element x to the back of queue.
  void push(int x) {
    std::stack<int> s;
    while (!_q.empty()) {
      s.push(_q.top());
      _q.pop();
    }
    _q.push(x);
    while (!s.empty()) {
      _q.push(s.top());
      s.pop();
    }
  }

  // Removes the element from in front of queue.
  void pop(void) {
    _q.pop();
  }

  // Get the front element.
  int peek(void) {
    return _q.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return _q.empty();
  }
private:
  std::stack<int> _q;
};

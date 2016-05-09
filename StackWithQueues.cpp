// https://leetcode.com/problems/implement-stack-using-queues/

#include <queue>

class Stack {
public:
  // Push element x onto stack.
  void push(int x) {
    _s.push(x);
    for (int i = 1; i < _s.size(); ++i) {
      _s.push(_s.front());
      _s.pop();
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    _s.pop();
  }

  // Get the top element.
  int top() {
    return _s.front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return _s.empty();
  }
private:
  std::queue<int> _s;
};

// https://leetcode.com/problems/reverse-linked-list/

function reverseList(head) {
  if (!head) return head

  const stack = []
  let current = head

  while (current) {
    stack.push(current)
    current = current.next
  }

  for (let i = stack.length - 1; i > -1; --i) {
    current = stack[i]
    current.next = stack[i - 1]
  }

  return stack[stack.length - 1]
}

public class AddTwoNumbers {
  public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
  }

  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    if (l1 == null && l2 == null) return null;
    if (l1 == null) l1 = new ListNode(0);
    if (l2 == null) l2 = new ListNode(0);

    int value = l1.val + l2.val;
    if (value > 9) {
      int carry = value / 10;
      value %= 10;
      if (l1.next != null) {
        l1.next.val += carry;
      } else {
        l1.next = new ListNode(carry);
      }
    }

    ListNode node = new ListNode(value);
    node.next = addTwoNumbers(l1.next, l2.next);
    return node;
  }
}

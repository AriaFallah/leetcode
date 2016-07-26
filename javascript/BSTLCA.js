// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

function lowestCommonAncestor(root, p, q) {
  if (!root || root === p || root === q) return root
  if (p.val < root.val && q.val < root.val) return lowestCommonAncestor(root.left, p, q)
  if (p.val > root.val && q.val > root.val) return lowestCommonAncestor(root.right, p, q)
  return root
}

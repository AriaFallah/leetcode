// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

function lowestCommonAncestor(root, p, q) {
  if (!root || root === p || root === q) return root
  const left  = lowestCommonAncestor(root.left, p, q)
  const right = lowestCommonAncestor(root.right, p, q)
  if (right && left) return root
  return left ? left : right
}

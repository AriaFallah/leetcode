// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
* @param {TreeNode} root
* @param {TreeNode} p
* @param {TreeNode} q
* @return {TreeNode}
*/
var lowestCommonAncestor = function(root, p, q) {
  if (!root || root === p || root === q) return root
  var left  = lowestCommonAncestor(root.left, p, q)
  var right = lowestCommonAncestor(root.right, p, q)
  if (right && left) return root
  return left ? left : right
};

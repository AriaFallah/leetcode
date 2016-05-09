// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
* @param {TreeNode} root
* @return {void} Do not return anything, modify root in-place instead.
*/
var flatten = function(root) {
  flattenHelper(root, null)
};

var flattenHelper = function(root, parent) {
  if (!root) return
  flattenHelper(root.left, root)
  if (parent) {
    parent.left  = null
    root.right   = parent.right
    parent.right = root
  }
  flattenHelper(root.right, root)
}

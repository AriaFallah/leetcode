// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

function flatten(root) {
  flattenHelper(root, null)
}

function flattenHelper(root, parent) {
  if (!root) return
  flattenHelper(root.left, root)
  if (parent) {
    parent.left = null
    root.right = parent.right
    parent.right = root
  }
  flattenHelper(root.right, root)
}

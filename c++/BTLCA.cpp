// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/*
  Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

  According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
  between two nodes v and w as the lowest node in T that has both v and w as descendants 
  (where we allow a node to be a descendant of itself).”
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    return left && right ? root : left ? left : right;
  }
};

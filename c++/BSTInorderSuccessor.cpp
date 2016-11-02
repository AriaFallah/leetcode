// https://leetcode.com/problems/inorder-successor-in-bst/

/*
  Given a binary search tree and a node in it, 
  find the in-order successor of that node in the BST.

  Note: If the given node has no in-order successor in the tree, return null.
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

enum Status { INCOMPLETE, PENDING, COMPLETE };

class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    Status s = INCOMPLETE;
    return inorder(root, p, s);
  }
private:
  TreeNode* inorder(TreeNode* cur, TreeNode* target, Status& s) {
    if (!cur || s == COMPLETE) return nullptr;
    TreeNode* left = inorder(cur->left, target, s);
    if (cur->val == target->val) {
      s = PENDING; 
    } else if (s == PENDING) {
      s = COMPLETE;
      return cur;
    }
    TreeNode* right = inorder(cur->right, target, s);
    return left ? left : right;
  }
};

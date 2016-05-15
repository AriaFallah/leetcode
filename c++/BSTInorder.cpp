// https://leetcode.com/problems/binary-tree-inorder-traversal/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(0), right(0) {}
};

#include <vector>
#include <stack>

class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> v = {};
    if (root == 0) return v;

    auto current = root;
    std::stack<TreeNode*> pending;

    while (current != 0 || !pending.empty()) {
      if (current) {
        pending.push(current);
        current = current->left;
      } else {
        TreeNode* node = pending.top();
        v.push_back(node->val);
        pending.pop();
        current = node->right;
      }
    }
    return v;
  }
};

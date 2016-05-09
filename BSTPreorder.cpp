// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> v = {};
    if (root == 0) return v;

    auto current = root;
    std::stack<TreeNode*> pending;

    while (current != 0 || !pending.empty()) {
      if (current != 0) {
        v.push_back(current->val);
        pending.push(current->right);
        current = current->left;
      } else {
        current = pending.top();
        pending.pop();
      }
    }
    return v;
  }
};

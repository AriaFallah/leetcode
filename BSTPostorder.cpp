// https://leetcode.com/problems/binary-tree-postorder-traversal/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(0), right(0) {}
};

// Copy pasted because I peeked solutions :'(
// http://articles.leetcode.com/2010/10/binary-tree-post-order-traversal.html

#include <vector>
#include <stack>

class Solution {
public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> v;
    if (!root) return v;
    std::stack<TreeNode*> s;
    s.push(root);
    TreeNode* prev = 0;
    while (!s.empty()) {
      TreeNode* curr = s.top();
      if (!prev || prev->left == curr || prev->right == curr) {
        if (curr->left)       s.push(curr->left);
        else if (curr->right) s.push(curr->right);
      } else if (curr->left == prev) {
        if (curr->right) s.push(curr->right);
      } else {
        v.push_back(curr->val);
        s.pop();
      }
      prev = curr;
    }
    return v;
  }
};

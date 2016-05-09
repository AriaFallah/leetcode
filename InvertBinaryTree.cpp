struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

#include <utility>

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    std::swap(root->right, root->left);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};

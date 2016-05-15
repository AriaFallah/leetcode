#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
  static int maxDepth(TreeNode* root) {
    if (root == 0) return 0;
    int left = 1 + maxDepth(root->left);
    int right = 1 + maxDepth(root->right);

    return std::max(left, right);
  }
};

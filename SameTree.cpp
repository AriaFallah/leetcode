struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == 0 && q == 0) return true;
    else if (p == 0) return false;
    else if (q == 0) return false;
    else if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

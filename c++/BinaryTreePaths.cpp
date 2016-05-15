// https://leetcode.com/problems/binary-tree-paths/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(0), right(0) {}
};

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> v;
    constructPath(root, "", v);
    return v;
  }
private:
  void constructPath(TreeNode* root, std::string s, std::vector<std::string>& v) {
    if (!root) return;
    if (!root->left && !root->right) v.push_back(s + std::to_string(root->val));

    constructPath(root->left, s + std::to_string(root->val) + "->", v);
    constructPath(root->right, s + std::to_string(root->val) + "->", v);
  }
};

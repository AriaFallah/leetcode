// https://leetcode.com/problems/binary-tree-paths/

/*
  Given a binary tree, return all root-to-leaf paths.

  For example, given the following binary tree:

     1
   /   \
  2     3
   \
    5

  All root-to-leaf paths are:
  ["1->2->5", "1->3"]
*/

#include <vector>
#include <string>

using std::vector;
using std::string;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return {};
    
    vector<string> paths;
    traverse(root, "", paths);
    return paths;
  }
private:
  void traverse(TreeNode* t, string const& s, vector<string>& paths) {
    if (!t->left && !t->right) {
      return paths.push_back(s + std::to_string(t->val));
    }
    if (t->left) traverse(t->left, s + std::to_string(t->val) + "->", paths);
    if (t->right) traverse(t->right, s + std::to_string(t->val) + "->", paths);
  }
};

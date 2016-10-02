// https://leetcode.com/problems/validate-binary-search-tree/

/*
  Given a binary tree, determine if it is a valid binary search tree (BST).

  Assume a BST is defined as follows:

  The left subtree of a node contains only nodes with keys less than the node's key.
  The right subtree of a node contains only nodes with keys greater than the node's key.
  Both the left and right subtrees must also be binary search trees.

  Example 1:
  2
  / \
  1   3
  Binary tree [2,1,3], return true.

  Example 2:

  1
  / \
  2   3
  Binary tree [1,2,3], return false.
*/

#include <vector>
#include <algorithm>

using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    return traverse(root->left, {}, { root->val }) && traverse(root->right, { root->val },  {});
  }
private:
  bool traverse(TreeNode* t, vector<int> const& maxes, vector<int> const& mins) {
    if (!t) return true;
    
    for (int x : maxes) {
      if (t->val <= x) return false;
    }
    for (int x : mins) {
      if (t->val >= x) return false;
    }

    vector<int> left_mins(mins); left_mins.push_back(t->val);
    vector<int> right_maxes(maxes); right_maxes.push_back(t->val);
    
    return traverse(t->left, maxes, left_mins) && traverse(t->right, right_maxes, mins);
  }
};

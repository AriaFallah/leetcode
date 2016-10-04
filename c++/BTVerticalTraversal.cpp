// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

/*
  Given a binary tree, return the vertical order traversal of its nodes' values. 
  (ie, from top to bottom, column by column).

  If two nodes are in the same row and column, the order should be from left to right.
*/

#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>

using std::map;
using std::pair;
using std::queue;
using std::vector;
using std::make_pair;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> v;
    map<int, vector<int>> col;
    
    traverse(root, 0, col);
    for (auto const& x : col) v.push_back(x.second);
    return v;
  }
private:
  void traverse(TreeNode* root, int count, map<int, vector<int>>& col) {
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, count));
    while (!q.empty()) {
      pair<TreeNode*, int> p = q.front(); q.pop();
      int c = p.second;
      TreeNode* cur = p.first;

      if (col.find(c) == col.end()) {
        col[c] = { cur->val };
      } else {
        col[c].push_back(cur->val);
      }
      
      if (cur->left) q.push(make_pair(cur->left, c - 1));
      if (cur->right) q.push(make_pair(cur->right, c + 1));
    }
  }
};

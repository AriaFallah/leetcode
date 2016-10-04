// https://leetcode.com/problems/binary-search-tree-iterator/

/*
  Implement an iterator over a binary search tree (BST). Your iterator will be 
  initialized with the root node of a BST.

  Calling next() will return the next smallest number in the BST.

  Note: next() and hasNext() should run in average O(1) time and uses O(h) 
  memory, where h is the height of the tree.

  Your BSTIterator will be called like this:
  BSTIterator i = BSTIterator(root);
  while (i.hasNext()) cout << i.next();
*/

#include <stack>

using std::stack;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
  explicit BSTIterator(TreeNode* root): s() {
    TreeNode* current = root;
    while(current) {
      s.push(current);
      current = current->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return s.size() > 0;
  }

  /** @return the next smallest number */
  int next() {
    int val = s.top()->val;
    TreeNode* current = s.top()->right; s.pop();
    
    while (current) {
      s.push(current);
      current = current->left;
    }
    
    return val;
  }
private:
  stack<TreeNode*> s;
};


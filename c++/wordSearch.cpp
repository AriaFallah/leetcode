// https://leetcode.com/problems/word-search/

/*
  Given a 2D board and a word, find if the word exists in the grid.

  The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells 
  are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

  For example,
  Given board =

  [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
  ]
  word = "ABCCED", -> returns true,
  word = "SEE", -> returns true,
  word = "ABCB", -> returns false.
*/

#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) return false;
    
    for (int row = 0; row < (int)board.size(); ++row) {
      for (int col = 0; col < (int)board[0].size(); ++col) {
        if (search(board, word, row, col, 0)) return true;
      }
    }

    return false;
  }
private:
  bool search (vector<vector<char>>& b, string const& word, int row, int col, int pos) {
    if (pos == (int)word.length()) return true;
    if (
      row < 0
      || col < 0
      || row == (int)b.size()
      || col == (int)b[0].size()
      || b[row][col] != word[pos]
    ) return false;

    // Save the value of the board and "visit" it
    char val = b[row][col];
    b[row][col] = '\0';
    
    bool res = search(b, word, row + 1, col, pos + 1)
        || search(b, word, row - 1, col, pos + 1)
        || search(b, word, row, col + 1, pos + 1)
        || search(b, word, row, col - 1, pos + 1);

    // Restore value to old value and return
    b[row][col] = val;
    return res;
  }
};

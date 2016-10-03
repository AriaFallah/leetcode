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
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

struct Loc {
  // Attribues
  int m_row;
  int m_col;

  // Constuctor
  Loc(int row, int col): m_row(row), m_col(col) {}

  // Equality operator
  bool operator==(Loc const& l) const {
    return m_row == l.m_row && m_col == l.m_col;
  }
};

struct loc_hash {
  size_t operator()(Loc const& l) const {
    return l.m_row * 31 + l.m_col;
  }
};

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) return false;
    
    unordered_set<Loc, loc_hash> visited;
    for (int row = 0; row < (int)board.size(); ++row) {
      for (int col = 0; col < (int)board[0].size(); ++col) {
        if (search(board, word, visited, Loc(row, col), 0)) return true;
      }
    }

    return false;
  }
private:
  bool search (vector<vector<char>> const& b, string const& word, unordered_set<Loc, loc_hash> v, Loc l, int pos) {
    if (pos == (int)word.length()) return true;
    if (
      v.find(l) != v.end()
      || l.m_row < 0
      || l.m_col < 0
      || l.m_row == (int)b.size()
      || l.m_col == (int)b[0].size()
      || b[l.m_row][l.m_col] != word[pos]
    ) return false;

    v.insert(l);
    return search(b, word, v, Loc(l.m_row + 1, l.m_col), pos + 1)
        || search(b, word, v, Loc(l.m_row - 1, l.m_col), pos + 1)
        || search(b, word, v, Loc(l.m_row, l.m_col + 1), pos + 1)
        || search(b, word, v, Loc(l.m_row, l.m_col - 1), pos + 1);
  }
};

// https://leetcode.com/problems/number-of-islands/

/*
  Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
  An island is surrounded by water and is formed by connecting adjacent lands 
  horizontally or vertically. You may assume all four edges of the grid are all 
  surrounded by water.

  Example 1:

  11110
  11010
  11000
  00000

  Answer: 1

  ------------------

  Example 2:

  11000
  11000
  00100
  00011

  Answer: 3
*/

#include <vector>

using std::vector;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;

    int count = 0;
    int rowSize = grid.size();
    int colSize = grid[0].size();
    vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));

    for (int row = 0; row < rowSize; ++row) {
      for (int col = 0; col < colSize; ++col) {
        if (!visited[row][col] && grid[row][col] != '0') {
          count++;
          visit(grid, visited, row, col, rowSize, colSize);
        }
      }
    }

    return count;
  }
private:
  void visit(vector<vector<char>> const& g, vector<vector<bool>>& v, int row, int col, int rs, int cs) {
    if (row < 0 || row > rs - 1 || col < 0 || col > cs - 1 || v[row][col] || g[row][col] == '0') return;
    v[row][col] = true;
    visit(g, v, row + 1, col, rs, cs);
    visit(g, v, row - 1, col, rs, cs);
    visit(g, v, row, col + 1, rs, cs);
    visit(g, v, row, col - 1, rs, cs);
  }
};

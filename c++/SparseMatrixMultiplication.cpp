// https://leetcode.com/problems/sparse-matrix-multiplication/

/*
  Given two sparse matrices A and B, return the result of AB.
  You may assume that A's column number is equal to B's row number.
*/

#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int ARows = A.size(), ACols = A[0].size();
    int BRows = B.size(), BCols = B[0].size();
    vector<vector<int>> prod(A.size(), vector<int>(B[0].size(), 0));

    if (ACols != BRows) return prod;
    
    for (int i = 0; i < ARows; ++i) {
      for (int j = 0; j < ACols; ++j) {
        if (A[i][j] == 0) continue;
        for (int k = 0; k < BCols; ++k) {
          if (B[j][k] == 0) continue;
          prod[i][k] += A[i][j] * B[j][k];
        }
      }
    }

    return prod;
  }
};

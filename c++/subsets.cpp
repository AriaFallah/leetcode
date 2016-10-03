// https://leetcode.com/problems/subsets/

/*
  Given a set of distinct integers, nums, return all possible subsets.

  Note: The solution set must not contain duplicate subsets.

  For example,
  If nums = [1,2,3], a solution is:

  [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
  ]
*/

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> v;
    vector<vector<int>> s;
    combinations(nums, v, s, 0);
    return s;
  }
private:
  void combinations(vector<int>& n, vector<int>& v, vector<vector<int>>& s, int pos) {
    s.push_back(v);
    for (int i = pos; i < (int)n.size(); ++i) {
      v.push_back(n[i]);
      combinations(n, v, s, i + 1);
      v.pop_back();
    }
  }
};


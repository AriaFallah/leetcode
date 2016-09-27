// https://leetcode.com/problems/house-robber/

/*
  You are a professional robber planning to rob houses along a street. 
  Each house has a certain amount of money stashed, the only constraint 
  stopping you from robbing each of them is that adjacent houses have 
  security system connected and it will automatically contact the police 
  if two adjacent houses were broken into on the same night.

  Given a list of non-negative integers representing the amount of 
  money of each house, determine the maximum amount of money you can 
  rob tonight without alerting the police.
*/

// f(n) = max(rob(n - 1), rob(n, n - 2))

#include <vector>

class Solution {
public:
  int rob(std::vector<int>& nums) {
    unsigned robberies[3] = { 0, 0, 0 };
    for (int house : nums) {
      robberies[0] = robberies[1];
      robberies[1] = robberies[2];
      robberies[2] = std::max(robberies[1], house + robberies[0]);
    }
    return robberies[2];
  }
};

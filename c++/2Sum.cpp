// https://leetcode.com/problems/two-sum/

/*
  Given an array of integers, return indices of the two numbers such that they add up 
  to a specific target.

  You may assume that each input would have exactly one solution.

  Example:
  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
*/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    
    for (int i = 0, len = nums.size(); i < len; ++i) m[nums[i]] = i; 
    for (int i = 0, len = nums.size(); i < len; ++i) {
      int x = target - nums[i];
      if (m.find(x) != m.end() && m[x] != i) return { i, m[x] };
    }
    return {};
  }
};

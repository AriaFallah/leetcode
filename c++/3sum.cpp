// https://leetcode.com/problems/3sum/

/*
  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
  Find all unique triplets in the array which gives the sum of zero.

  Note: The solution set must not contain duplicate triplets.

  For example, given array S = [-1, 0, 1, 2, -1, -4],

  A solution set is:
  [
  [-1, 0, 1],
  [-1, -1, 2]
  ]
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> s;
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0, len = nums.size(); i < len - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int l = i + 1, h = len - 1; l < h;) {
        if (nums[i] + nums[l] + nums[h] > 0) h--;
        else if (nums[i] + nums[l] + nums[h] < 0) l++;
        else {
          s.push_back({ nums[i], nums[l], nums[h] });
          while (l < h && nums[l] == nums[l + 1]) l++;
          while (l < h && nums[h] == nums[h - 1]) h--;
          l++; h--;
        }
      }
    }

    return s;
  }
};

// https://leetcode.com/problems/increasing-triplet-subsequence/

#import <vector>

class Solution {
public:
  bool increasingTriplet(std::vector<int>& nums) {
    int min = INT_MAX;
    int min2 = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= min) {
        min = nums[i];
      } else if (nums[i] <= min2) {
        min2 = nums[i];
      } else {
        return true;
      }
    }
    return false;
  }
};

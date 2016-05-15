// https://leetcode.com/problems/move-zeroes/

#include <vector>
#include <utility>

class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = i; j > 0; --j) {
        if (nums[j - 1] == 0) {
          std::swap(nums[j], nums[j - 1]);
        } else break;
      }
    }
  }
};

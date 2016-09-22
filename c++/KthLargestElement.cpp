// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <vector>
#include <algorithm>

class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    const int size = nums.size();
    std::sort(nums.begin(), nums.end());
    return nums[size - k];
  }
};

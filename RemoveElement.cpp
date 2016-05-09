// https://leetcode.com/problems/remove-element/

#include <vector>

class Solution {
public:
  int removeElement(std::vector<int>& nums, int val) {
    int front = 0, lookahead = 0;
    for(; lookahead < nums.size(); lookahead++) {
      if (nums[lookahead] != val)  {
        nums[front++] = nums[lookahead];
      }
    }
    return front;
  }
};

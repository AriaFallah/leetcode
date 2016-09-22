// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <vector>
#include <algorithm>

/*
  Given an array of n positive integers and a positive integer s, 
  find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

  For example, given the array [2,3,1,2,4,3] and s = 7
  the subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution {
public:
  int minSubArrayLen(int s, std::vector<int>& nums) {
    int sum = 0;
    int start = 0;
    int current = 0;
    int min = INT_MAX;

    while (current < (int)nums.size()) {
      sum += nums[current++];

      while (sum >= s) {
        min = std::min(min, current - start);
        sum -= nums[start++];
      }
    }

    return min == INT_MAX ? 0 : min;
  }
};

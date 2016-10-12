// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

/*
  Given an array nums and a target value k, find the maximum length of a 
  subarray that sums to k. If there isn't one, return 0 instead.

  Example 1:
  Given nums = [1, -1, 5, -2, 3], k = 3,
  return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

  Example 2:
  Given nums = [-2, -1, 2, 1], k = 1,
  return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

  Follow Up:
  Can you do it in O(n) time?
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
  int maxSubArrayLen(vector<int>& a, int k) {
    int maxLen = 0, sum = 0;
    unordered_map<int, int> map = { { 0, -1 } };
        
    for (int i = 0; i < (int)a.size(); ++i) {
      sum += a[i];
      if (map.find(sum) == map.end()) map[sum] = i;
      if (map.find(sum - k) != map.end()) maxLen = std::max(maxLen, i - map[sum - k]);
    }
        
    return maxLen;
  }
};


// https://leetcode.com/problems/single-number/

// Given an array of integers, every element appears twice except for one. Find that single one.

#include <vector>
#include <unordered_map>

class Solution {
public:
  int singleNumber(std::vector<int>& nums) {
    std::unordered_map<int, int> m;
    
    for (int num : nums) {
      if (m.find(num) == m.end()) m[num] = 0;
      m[num]++;
    }

    for (auto const& x : m) {
      if (x.second == 1) {
        return x.first;
      }
    }
    
    return 0;
  }
};


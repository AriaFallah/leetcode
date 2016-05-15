// https://leetcode.com/problems/find-the-duplicate-number/

#include <unordered_map>
#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> map;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (map.find(nums[i]) == map.end()) map[nums[i]] = 1;
      else map[nums[i]]++;
    }

    for (auto x : map) {
      if (x.second > 1) return x.first;
    }

    return 0;
  }
};

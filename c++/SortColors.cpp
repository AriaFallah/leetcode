// https://leetcode.com/problems/sort-colors/

/*
  Given an array with n objects colored red, white or blue, sort them so that objects of the same color are 
  adjacent, with the colors in the order red, white and blue.

  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

  Note:
  You are not suppose to use the library's sort function for this problem.
*/

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int pos = 0;
    unordered_map<int, int> m;
    
    for (int x : nums) {
      if (m.find(x) == m.end()) m[x] = 0;
      m[x]++;
    }

    for (int i = 0; i < 3; ++i) {
      if (m.find(i) == m.end()) continue;
      for (int j = 0; j < m[i]; ++j) {
        nums[pos++] = i;
      }
    }
  }
};

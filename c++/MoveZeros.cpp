// https://leetcode.com/problems/move-zeroes/

#include <vector>
#include <utility>
#include <iostream>

/*
  Given an array nums, write a function to move all 0's to the end of it while maintaining
  the relative order of the non-zero elements.

  For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should 
  be [1, 3, 12, 0, 0].

  Note:
  You must do this in-place without making a copy of the array.
  Minimize the total number of operations.
*/

class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    size_t size = nums.size();
    if (size < 2) return;
    
    unsigned p1 = 0;
    unsigned p2 = 1;
    
    for (;;) {
      while (nums[p1] != 0) p1++;
      while (nums[p2] == 0 || p2 < p1) p2++;
      if (p2 < size) std::swap(nums[p1++], nums[p2++]);
      else break;
    }
  }
};

int main() {
  Solution s;
  std::vector<int> v = { 0, 1, 0, 3, 12 };
  s.moveZeroes(v);
  for (auto x : v) std::cout << x << " ";
}

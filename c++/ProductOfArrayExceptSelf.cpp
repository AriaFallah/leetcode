// https://leetcode.com/problems/product-of-array-except-self/

/*
  Given an array of n integers where n > 1, nums, 
  return an array output such that output[i] is equal 
  to the product of all the elements of nums except nums[i].

  Solve it without division and in O(n).

  For example, given [1,2,3,4], return [24,12,8,6].
*/

// [2, 6, 12, 1]

#include <vector>

using std::vector;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> result(size, 1);
    
    for (int i = 1; i < size; i++) {
      result[i] = result[i - 1] * nums[i - 1];
    }
    
    for (int i = size - 1, r = 1; i >= 0; i--) {
      result[i] *= r;
      r *= nums[i];
    }

    return result;
  }
};

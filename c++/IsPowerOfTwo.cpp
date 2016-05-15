// https://leetcode.com/problems/power-of-two/

#include <complex>

class Solution {
public:
  bool isPowerOfTwo(int n) {
    return (int)std::log2(n) == std::log2(n);
  }
};

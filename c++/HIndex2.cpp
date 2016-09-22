// https://leetcode.com/problems/h-index-ii/

#include <vector>
#include <iostream>

class Solution {
public:
  int hIndex(std::vector<int>& citations) {
    const int size = citations.size();

    for (int i = 0; i < size; ++i) {
      const int remaining = size - i;
      if (citations[i] >= remaining) return remaining;
    }

    return 0;
  }
};

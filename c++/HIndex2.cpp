// https://leetcode.com/problems/h-index-ii/

#import <vector>
#import <iostream>

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

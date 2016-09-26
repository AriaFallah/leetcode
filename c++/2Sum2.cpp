// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/*
  Given an array of integers that is already sorted in ascending order, find two
  numbers such that they add up to a specific target number.

  The function twoSum should return indices of the two numbers such that they 
  add up to the target, where index1 must be less than index2. Please note that 
  your returned answers (both index1 and index2) are not zero-based.

  You may assume that each input would have exactly one solution.

  Input: numbers={2, 7, 11, 15}, target=9
  Output: index1=1, index2=2
*/

#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int l = 0, h = numbers.size() - 1;
    while (h > l) {
      int x = numbers[h] + numbers[l];
      if (x == target) {
        return { l + 1, h + 1 };
      } else if (x < target) {
        l++;
      } else {
        h--;
      }
    }
    return {};
  }
};


// Binary Search exceeds time limit
class BadSolution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    for (size_t i = 0, len = numbers.size(); i < len; ++i) {
      int x = target - numbers[i];
      int index = binarySearch(numbers, x);
      if (index != -1 && index != (int)i) {
        if (index < (int)i) return { (index + 1), (int)(i + 1) };
        else return { (int)(i + 1), (index + 1) };
      }
    }
    return {};
  }
private:
  template <typename T>
  int binarySearch(std::vector<T> const& v, T t) {
    unsigned s = v.size(), l = 0, h = s - 1, m = (h - l) / 2; 
    while (h > l) {
      if (v[m] == t) return m;
      else if (v[m] > t) {
        l = m;
        m = (h - l) / 2;
      } else {
        h = m;
        m = (h - l) / 2;
      }
    }
    return -1;
  }
};

// https://leetcode.com/problems/random-pick-index/

/*
  Given an array of integers with possible duplicates, randomly 
  output the index of a given target number. You can assume 
  that the given target number must exist in the array.
*/

#include <vector>
#include <random>
#include <unordered_map>

using std::vector;
using std::unordered_map;

struct RandGen {
  std::random_device rd;
  std::mt19937 gen;
  RandGen(): rd(), gen(rd()) {}
};

class Solution {
public:
  explicit Solution(vector<int> nums): m_nums(nums) {}
  int pick(int target) {
    int result = -1, count = 0;

    for (int i = 0; i < (int)m_nums.size(); ++i) {
      if (m_nums[i] != target) continue;
      
      std::uniform_int_distribution<int> dis(0, count++);
      if (dis(m_rg.gen) == 0) {
        result = i;
      }
    }
    return result;
  }
private:
  RandGen m_rg;
  vector<int> m_nums;
};

class Solution2 {
public:
  explicit Solution2(vector<int> nums) {
    // Init cache
    for (int i = 0; i < (int)nums.size(); ++i) {
      int key = nums[i];
      if (m_cache.find(key) == m_cache.end()) m_cache[key] = { i };
      else m_cache[key].push_back(i);
    }
  }
    
  int pick(int target) {
    vector<int> indices = m_cache[target];
    if (indices.size() == 1) return indices[0];
    std::uniform_int_distribution<int> dis(0, indices.size() - 1);
    return indices[dis(m_gen.gen)];
  }
private:
  RandGen m_gen;
  unordered_map<int, vector<int>> m_cache;
};

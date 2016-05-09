#include <vector>
#include <unordered_map>

class Solution {
public:
  static int singleNumber(std::vector<int>& nums) {
    std::unordered_map<int, int> numLookup;
    for (size_t i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (numLookup.find(num) == numLookup.end()) numLookup[num] = 1;
      else numLookup[num]++;
    }

    for (auto const& x : numLookup) {
      if (x.second == 1) {
        return x.first;
      }
    }
    return 0;
  }
};

int main() {
  return 0;
}

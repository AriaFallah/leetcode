// https://leetcode.com/problems/anagrams/

/*
  Given an array of strings, group anagrams together.

  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
  Return:

  [
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
  ]

  Note: All inputs will be in lower-case.
*/

#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    while (strs.size() > 0) {
      int pos = strs.size() - 1;
      vector<string> v = { strs[pos] };
      unordered_map<char, int> m = letterCounts(strs[pos]);

      // mangle strs, but whatever
      strs.erase(strs.begin() + pos--);
      for (int i = pos; i >= 0; --i) {
        if (isAnagram(m, strs[i])) {
          v.push_back(strs[i]);
          strs.erase(strs.begin() + i);
        }
      }
      pos++;
      result.push_back(v);
    }
    
    return result;
  }
private:
  bool isAnagram(unordered_map<char, int> const& m, string const& s) {
    unordered_map<char, int> n = letterCounts(s);
    if (m.size() != n.size()) return false;
    for (auto x : m) {
      if (x.second != n[x.first]) return false;
    }
    return true;
  }
  
  unordered_map<char, int> letterCounts(std::string const& s) {
    unordered_map<char, int> m;
    for (char c : s) {
      if (m.find(c) != m.end()) m[c] = 0;
      m[c]++;
    }
    return m;
  }
};

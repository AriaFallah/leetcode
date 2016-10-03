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
    vector<vector<string>> anagrams;
    unordered_map<string, vector<string>> mp;
    
    for (string s : strs) {
      string t = s; 
      sort(t.begin(), t.end());
      mp[t].push_back(s);
    }
        
    for (auto m : mp) { 
      vector<string> anagram(m.second.begin(), m.second.end());
      anagrams.push_back(anagram);
    }
        
    return anagrams;
  }
};

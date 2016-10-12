// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/*
  Given a digit string, return all possible letter combinations that the number could represent.
  A mapping of digit to letters (just like on the telephone buttons) is given below.

  Input:Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.length() == 0) return {};
    
    vector<string> res;
    vector<vector<string>> sets;
    vector<string> mappings[8] = {
      { "a", "b", "c" },
      { "d", "e", "f" },
      { "g", "h", "i" },
      { "j", "k", "l" },
      { "m", "n", "o" },
      { "p", "q", "r", "s"},
      { "t", "u", "v" },
      { "w", "x", "y", "z" }
    };

    for (char c : digits) {
      if (c >= '2' && c <= '9') {
        sets.push_back(mappings[c - '0' - 2]); 
      }
    }

    res = sets[0];
    for (size_t i = 1, len = sets.size(); i < len; ++i) {
      res = generateCombos(res, sets[i]);
    }

    return res;
  }
private:
  vector<string> generateCombos(vector<string> const& prev, vector<string> const& cur) {
    vector<string> res;
    for (string s : prev) {
      for (string s2 : cur) {
        res.push_back(s + s2);
      }
    }
    return res;
  }
};


// Recursive solution
class Solution2 {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> v;
    search(digits, 0, "", v, digits.length());
    return v;
  }
private:
  string const digit_map[8]{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void search(const string& digits, int pos, string path, vector<string>& v, int len) {
    if (pos == len) return;
    string s = digit_map[digits[pos] - '2'];
    for (size_t i = 0, sLen = s.length(); i < sLen; ++i) {
      if (pos == len - 1) v.push_back(path + s[i]);
      else search(digits, pos + 1, path + s[i], v, len);
    }
  }
};

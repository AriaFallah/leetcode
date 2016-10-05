// https://leetcode.com/problems/one-edit-distance/

/*
  Given two strings S and T, determine if they are both one edit distance apart.
*/

#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int sLen = s.length(), tLen = t.length();
    
    if (tLen > sLen) return isOneEditDistance(t, s);
    if (sLen - tLen > 1) return false;

    int count = 0;
    for (int i = 0, j = 0; i < sLen; ++i, ++j) {
      if (s[i] != t[j]) {
        if (count++ <= 1) {
          if (sLen == tLen) t[j] = s[i];
          else j--;
        }
        else return false;
      }
    }

    return count == 1;
  }
};

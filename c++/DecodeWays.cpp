// https://leetcode.com/problems/decode-ways/
    
/*
  A message containing letters from A-Z is being encoded to numbers using the following mapping:

  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26

  Given an encoded message containing digits, determine the total number of ways to decode it.

  For example,
  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

  The number of ways decoding "12" is 2.
*/

#include <string>

using std::string;

class Solution {
public:
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;

    int ways[3] = { 0, 1, 1 };
    int letters[2] = { 0, s[0] - '0' };
    
    for (size_t i = 1, len = s.length(); i < len; ++i) {
      ways[0] = ways[1];
      ways[1] = ways[2];
      letters[0] = letters[1];
      letters[1] = s[i] - '0';
      
      ways[2] =
        ways[1] * (letters[1] != 0)
        + ways[0] * (letters[0] != 0 && letters[0] * 10 + letters[1] <= 26);
    }

    return ways[2];
  }    
};

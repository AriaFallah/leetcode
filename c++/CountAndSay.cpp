// https://leetcode.com/problems/count-and-say/

/*
  The count-and-say sequence is the sequence of integers beginning as follows:
  1, 11, 21, 1211, 111221, ...

  1 is read off as "one 1" or 11.
  11 is read off as "two 1s" or 21.
  21 is read off as "one 2, then one 1" or 1211.
  Given an integer n, generate the nth sequence.

  Note: The sequence of integers will be represented as a string.
*/

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
  string countAndSay(int n) {
    if (n < 2) return "1";
    
    string s = "11";
    for (int i = 2; i < n; ++i) {
      s = seq(s);
    }
    
    return s;
  }
private:
  string seq(string s) {
    int pos = 0;
    int count = 1;
    string res = "";

    while (pos < (int)s.length()) {
      char prev = s[pos];
      if (pos == (int)s.length() - 1 || prev != s[pos + 1]) {
        res += std::to_string(count) + prev;
        count = 0;
      }
      pos++, count++;
    }
    
    return res;
  }
};

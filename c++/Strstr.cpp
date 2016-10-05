// https://leetcode.com/problems/implement-strstr/

/*
  Implement strStr().

  Returns the index of the first occurrence of needle in haystack, or -1 if 
  needle is not part of haystack.
*/

#include <string>

using std::string;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int len = needle.length();
    if (len == 0) return 0;
    
    for (int i = 0; i < (int)haystack.length(); ++i) {
      if (haystack[i] == needle[0] && haystack.substr(i, len) == needle) return i;
    }
    
    return -1;
  }
};

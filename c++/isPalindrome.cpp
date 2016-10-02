// https://leetcode.com/problems/valid-palindrome/

/*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  For example,
  "A man, a plan, a canal: Panama" is a palindrome.
  "race a car" is not a palindrome.
*/

#include <string>
#include <cctype>

using std::string;

class Solution {
public:
  bool isPalindrome(string s) {
    size_t size = s.size();
    int lo = 0, hi = size - 1;
    while (true) {
      // Skip nonalphanumeric chars
      while(lo < hi && !std::isalnum(s[lo])) lo++;
      while(lo < hi && !std::isalnum(s[hi])) hi--;
      
      // Break if lo > hi
      if (lo > hi) break;
      if (std::tolower(s[lo++]) != std::tolower(s[hi--])) return false;
    }
    return true;
  }
};

// https://leetcode.com/problems/word-break/

/*

  Given a string s and a dictionary of words dict, determine if s can be segmented into a 
  space-separated sequence of one or more dictionary words.

  For example, given
  s = "leetcode",
  dict = ["leet", "code"].

  Return true because "leetcode" can be segmented as "leet code".
*/

#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

// leet
// false false false true

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    vector<bool> dp(s.length() + 1, false);
    dp.back() = true;

    // Start at the second to last letter of the word
    for (int offset = s.length() - 1; offset >= 0; offset--) {
      
      // Start at the offset, and increase substring length
      for (size_t pos = offset, len = s.length(); pos < len; pos++) {
        
        // When you reach a previous word boundary, check if current substring is also a word
        if (dp[pos + 1] == true && wordDict.find(s.substr(offset, pos + 1 - offset)) != wordDict.end()) {
          
          // Set position of first letter of word to true
          dp[offset] = true;
          break;
        }
      }
    }

    // If the first entry is true
    // It means that there was a word before it (and a word before that word and so one)
    return dp[0];
  }
};

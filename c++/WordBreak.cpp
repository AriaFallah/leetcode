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
#include <utility>
#include <unordered_set>
#include <unordered_map>

using std::pair;
using std::string;
using std::vector;
using std::unordered_set;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    return backTrack(s, 0, 0, wordDict, s.length());
  }
private:
  vector<pair<unsigned, unsigned>> m_words;

  bool backTrack(string s, unsigned offset, unsigned pos, unordered_set<string>& d, size_t len) {
    if (pos == len) {
      if (m_words.size() > offset) {
        auto const& p = m_words.back(); m_words.pop_back();
        return backTrack(s, p.first, p.second + 1, d, len);
      } else {
        return false;
      }
    }

    string sub = s.substr(offset, pos + 1 - offset);
    if (d.find(sub) != d.end()) {
      if (pos == len - 1) return true;
      else {
        m_words.push_back(std::make_pair(offset, pos));
        return backTrack(s, pos + 1, pos + 1, d, len);
      }
    }

    return backTrack(s, offset, pos + 1, d, len);
  }
};

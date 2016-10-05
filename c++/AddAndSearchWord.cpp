// https://leetcode.com/problems/add-and-search-word-data-structure-design/

/*
  Design a data structure that supports the following two operations:

  void addWord(word)
  bool search(word)
  search(word) can search a literal word or a regular expression string 
  containing only letters a-z or a dot. A "." means it can represent any one letter.

  For example:

  addWord("bad")
  addWord("dad")
  addWord("mad")
  search("pad") -> false
  search("bad") -> true
  search(".ad") -> true
  search("b..") -> true
*/

#include <string>

using std::string;

const int ALPHABET_LENGTH = 26;

struct TrieNode {
  bool isWord;
  TrieNode* m_next[ALPHABET_LENGTH];
  TrieNode(): isWord(false) {
    for (int i = 0; i < ALPHABET_LENGTH; ++i) m_next[i] = nullptr;
  }
};

class WordDictionary {
public:
  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode* current = m_root;
    
    for (int i = 0; i < (int)word.length(); ++i) {
      int const index = word[i] - 'a';
      if (current->m_next[index] == nullptr) current->m_next[index] = new TrieNode();
      current = current->m_next[index];
    }

    current->isWord = true;
  }

  bool search(string word) {
    return helpSearch(m_root, word, 0);
  }
private:
  TrieNode* m_root = new TrieNode();

  bool helpSearch(TrieNode* t, string const& word, int const pos) {
    if (t == nullptr) return false;
    if (pos >= (int)word.length()) return t->isWord;
    
    // If dot, search all possible paths
    if (word[pos] == '.') {
      for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        if (helpSearch(t->m_next[i], word, pos + 1)) return true;
      }
      return false;
    }

    return helpSearch(t->m_next[word[pos] - 'a'], word, pos + 1);
  }
};

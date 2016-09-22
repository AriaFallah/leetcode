// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
#include <iostream>

const int ALPHABET_LENGTH = 26;

class Trie {
private:
  class TrieNode {
  public:
    // Private variables
    bool isWord;
    TrieNode* m_next[26];

    // Constructor
    TrieNode(): isWord(false) {
      for (int i = 0; i < ALPHABET_LENGTH; ++i) m_next[i] = NULL;
    }

    // Destructor
    ~TrieNode() {
      for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        cleanup(m_next[i]);
      }
    }
  private:
    // Helper for destructor
    void cleanup(TrieNode* x) {
      if (x == NULL) return;
      for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        TrieNode* node = x->m_next[i];
        if (node != NULL) {
          cleanup(node);
          x->m_next[i] = NULL;
        }
      }
      delete x;
    }
  };
public:
  Trie(): m_root(new TrieNode()) {}
  ~Trie() { delete m_root; }

  // Adds a word into the data structure.
  void insert(std::string word) {
    TrieNode* current = m_root;
    const int length = word.length();

    for (int i = 0; i < length; ++i) {
      const int c = word.at(i) - 'a';
      if (!current->m_next[c]) current->m_next[c] = new TrieNode();
      current = current->m_next[c];
    }

    current->isWord = true;
  }

  // Search the Trie for a word
  bool search(std::string word) {
    TrieNode* current = m_root;
    const int length = word.length();

    for (int i = 0; i < length; ++i) {
      const int c = word.at(i) - 'a';
      if (!current->m_next[c]) return false;
      current = current->m_next[c];
    }

    return current->isWord;
  }

  // Search the Trie for a word that starts with the given prefix
  bool startsWith(const std::string& prefix) {
    TrieNode* current = m_root;
    const int length = prefix.length();

    for (int i = 0; i < length; ++i) {
      const int c = prefix.at(i) - 'a';
      if (!current->m_next[c]) return false;
      current = current->m_next[c];
    }

    return true;
  }
private:
  TrieNode* m_root;
};

int main() {
  Trie t;
  
  t.insert("ab");
  t.insert("bc");
  
  std::cout << t.search("b") << t.search("ab") << t.startsWith("b") << std::endl;
}

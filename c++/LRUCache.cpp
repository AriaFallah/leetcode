// https://leetcode.com/problems/lru-cache/

/*
  Design and implement a data structure for Least Recently Used (LRU) cache. 
  It should support the following operations: get and set.

  get(key) - Get the value (will always be positive) of the key if 
  the key exists in the cache, otherwise return -1.

  set(key, value) - Set or insert the value if the key is not already present. 
  When the cache reached its capacity, it should invalidate the least 
  recently used item before inserting a new item.
*/

#include <deque>
#include <iostream>
#include <utility>
#include <unordered_map>

using std::pair;
using std::deque;
using std::unordered_map;

class LRUCache {
public:
  explicit LRUCache(int capacity): m_capacity(capacity - 1) {}
    
  int get(int key) {
    auto cacheIter = m_cache.find(key);
    return cacheIter != m_cache.end() ? prioritize(cacheIter, key) : -1;
  }
    
  void set(int key, int value) {
    std::cout << "setting " << key << " to " << value << std::endl;
    auto cacheIter = m_cache.find(key);
    
    if (cacheIter != m_cache.end()) {
      prioritize(cacheIter, key);
      m_keys.front().second = value;
    } else {
      if (m_keys.size() > m_capacity) {
        m_cache.erase(m_keys.back().first);
        m_keys.pop_back();
      }
      m_keys.push_front(std::make_pair(key, value));
    }

    for (auto x : m_keys) std::cout << x.first << " ";
    std::cout << std::endl << std::endl;

    m_cache[key] = m_keys.begin();
  }
private:
  size_t m_capacity;
  deque<pair<int, int>> m_keys;
  unordered_map<int, deque<pair<int, int>>::iterator> m_cache;

  int prioritize(unordered_map<int, deque<pair<int, int>>::iterator>::iterator mapIter, int key) {
    auto pairIter = mapIter->second;
    int val = pairIter->second;
    m_keys.push_front(std::move(*pairIter));
    m_keys.erase(pairIter);
    m_cache[key] = m_keys.begin();
    return val;
  }
};

int main() {
  LRUCache c(105);

  c.set(33,219);
  c.get(39);
  c.set(96,56);
  c.get(129);
  c.get(115);
  c.get(112);
  c.set(3,280);
  c.get(40);
  c.set(85,193);
  c.set(10,10);
  c.set(100,136);
  c.set(12,66);
  c.set(81,261);
  c.set(33,58);
  c.get(3);
  c.set(121,308);
  c.set(129,263);
  c.get(105);
  c.set(104,38);
  c.set(65,85);
  c.set(3,141);
  c.set(29,30);
  c.set(80,191);
  c.set(52,191);
  c.set(8,300);
  c.get(136);
  c.set(48,261);
  c.set(3,193);
  c.set(133,193);
  c.set(60,183);
  c.set(128,148);
  c.set(52,176);
}

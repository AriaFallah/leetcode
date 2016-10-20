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

#include <list>
#include <utility>
#include <unordered_map>

using std::pair;
using std::list;
using std::unordered_map;

class LRUCache {
public:
  explicit LRUCache(int capacity): m_capacity(capacity - 1) {}
    
  int get(int key) {
    auto cacheIter = m_cache.find(key);
    return cacheIter != m_cache.end() ? prioritize(cacheIter->second) : -1;
  }
    
  void set(int key, int value) {
    auto cacheIter = m_cache.find(key);

    // Key already exists -> move to front of cache and adjust value at key
    if (cacheIter != m_cache.end()) {
      prioritize(cacheIter->second);
      cacheIter->second->second = value;
      return;
    }

    // Capacity max reached -> remove least used cache value
    if (m_keys.size() > m_capacity) {
      m_cache.erase(m_keys.back().first);
      m_keys.pop_back();
    }

    // Key didn't exist -> add new pair to front of cache
    m_keys.push_front(std::make_pair(key, value));
    m_cache[key] = m_keys.begin();
  }
private:
  size_t m_capacity;
  list<pair<int, int>> m_keys;
  unordered_map<int, list<pair<int, int>>::iterator> m_cache;

  // Moves pair to the front of the cache
  int prioritize(list<pair<int, int>>::iterator listIter) {
    m_keys.splice(m_keys.begin(), m_keys, listIter);
    return listIter->second;
  }
};

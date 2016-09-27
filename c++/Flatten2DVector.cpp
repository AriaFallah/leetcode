// https://leetcode.com/problems/flatten-2d-vector/

/*
  Implement an iterator to flatten a 2d vector.

  For example,
  Given 2d vector =

  [
  [1,2],
  [3],
  [4,5,6]
  ]

  By calling next repeatedly until hasNext returns false, the order of elements returned
  by next should be: [1,2,3,4,5,6].

  Your Vector2D object will be instantiated and called as such:
  Vector2D i(vec2d);
  while (i.hasNext()) cout << i.next();
*/

#include <vector>
#include <iostream>

class Vector2D {
public:
  explicit Vector2D(std::vector<std::vector<int>>& vec2d): m_col(0), m_size(0), m_vec() {
    for (auto x : vec2d) {
      for (auto y : x) m_vec.push_back(y);
    }
    m_size = m_vec.size();
  }

  int next() {
    return m_vec[m_col++];
  }

  bool hasNext() {
    return m_col < m_size;
  }
private:
  int m_col;
  int m_size;
  std::vector<int> m_vec;
};

class Vector2DIter {
public:
  explicit Vector2DIter(std::vector<std::vector<int>>& vec2d)
    : m_col(0),
      m_end(vec2d.end()),
      m_row(vec2d.begin())
  {}

  int next() {
    return (*m_row)[m_col++];
  }

  bool hasNext() {
    while (m_col >= (*m_row).size()) ++m_row, m_col = 0;
    return m_row != m_end;
  }
private:
  size_t m_col;
  std::vector<std::vector<int>>::iterator m_end;
  std::vector<std::vector<int>>::iterator m_row;
};

int main() {
  std::vector<std::vector<int>> vec = { {1, 2}, {3}, {4, 5, 6} };
  Vector2DIter v(vec);

  while (v.hasNext()) {
    std::cout << v.next() << std::endl;
  }
}


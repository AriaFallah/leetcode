// https://leetcode.com/problems/flatten-nested-list-iterator/
#include <vector>

// Just to get rid of annoying syntax errors
struct NestedInteger {
  NestedInteger();
  bool isInteger() const;
  int getInteger() const;
  std::vector<NestedInteger> getList() const;
};

class NestedIterator {
public:
  explicit NestedIterator(std::vector<NestedInteger> &nestedList): m_counter(0) {
    for (auto const x : nestedList) populateList(x);
  }

  int next() {
    return m_v[m_counter++];
  }

  bool hasNext() {
    return m_counter < (int)(m_v.size());
  }
private:
  int m_counter;
  std::vector<int> m_v;

  void populateList(NestedInteger x) {
    if (x.isInteger()) m_v.push_back(x.getInteger());
    else for (auto const y : x.getList()) populateList(y);
  }
};

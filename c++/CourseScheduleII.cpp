// https://leetcode.com/problems/course-schedule-ii/

/*
  There are a total of n courses you have to take, labeled from 0 to n - 1.

  Some courses may have prerequisites, for example to take course 0
  you have to first take course 1, which is expressed as a pair: [0,1]

  Given the total number of courses and a list of prerequisite pairs, 
  return the ordering of courses you should take to finish all courses.

  There may be multiple correct orders, you just need to return one of them. 
  If it is impossible to finish all courses, return an empty array.

  For example:

  2, [[1,0]]
  There are a total of 2 courses to take. To take course 1 you should 
  have finished course 0. So the correct course order is [0,1]

  4, [[1,0],[2,0],[3,1],[3,2]]
  There are a total of 4 courses to take. To take course 3 you should 
  have finished both courses 1 and 2. Both courses 1 and 2 should be taken 
  after you finished course 0. So one correct course order is [0,1,2,3]. 
  Another correct ordering is [0,2,1,3].
*/


#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_set>

struct GraphNode {
  unsigned m_indegree;
  std::unordered_set<int> m_edges;
  GraphNode(): m_indegree(0), m_edges() {}
};

class Solution {
public:
  std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) const {
    std::vector<int> ordering;
    std::vector<int> topNodes;
    std::vector<GraphNode*> graph(numCourses, nullptr);

    // Build a graph from the edges
    for (size_t i = 0; i < prerequisites.size(); ++i) {
      auto const& edge = prerequisites[i];
      
      if (graph[edge.first] == nullptr) {
        graph[edge.first] = new GraphNode();
      } if (graph[edge.second] == nullptr) {
        graph[edge.second] = new GraphNode();
      }
      
      auto& edges = graph[edge.second]->m_edges;
      if (edges.find(edge.first) == edges.end()) {
        edges.insert(edge.first);
        graph[edge.first]->m_indegree++;
      }
    }

    // Push edges with degree 0 into topNodes
    for (int i = 0; i < numCourses; ++i) {
      if (graph[i] == nullptr) ordering.push_back(i);
      else if (graph[i]->m_indegree == 0) topNodes.push_back(i);
    }

    // Kahn's algorithm
    while (topNodes.size() > 0) {
      int const node = topNodes.back(); 
      auto const& edges = graph[node]->m_edges;

      topNodes.pop_back();
      ordering.push_back(node);
      for (int const node : edges) {
        GraphNode* const g = graph[node];
        g->m_indegree--;
        if (g->m_indegree == 0) {
          topNodes.push_back(node);
        }
      }
    }

    // If all nodes don't have a degree of 0 then there's a cycle
    for (int i = 0; i < numCourses; ++i) {
      if (graph[i] && graph[i]->m_indegree != 0) {
        ordering = {};
        break;
      }
    }

    // Clean up memory and return
    for (int i = 0; i < numCourses; ++i) {
      if (graph[i] != nullptr) delete graph[i];
    }
    
    return ordering;
  }
};

int main() {
  Solution s;
  std::pair<int, int> pair1 = std::make_pair(1, 0);
  std::pair<int, int> pair2 = std::make_pair(2, 0);
  
  std::vector<std::pair<int,int>> vec = { pair1, pair2 };
  auto ordering = s.findOrder(4, vec);
  
  std::cout << "RESULTS\n";
  for (auto x : ordering)
    std::cout << x << std::endl;
}

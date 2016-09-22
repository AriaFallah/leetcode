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
  Another correct ordering is[0,2,1,3].
*/


#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

struct GraphNode {
  int m_value;
  bool visited;
  std::vector<GraphNode*> m_edges;
  explicit GraphNode(int value): m_value(value), visited(false), m_edges() {}
};

class Solution {
public:
  std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) const {
    std::vector<int> ordering;
    std::vector<GraphNode*> graph(numCourses);

    // Construct a graph of the pairs
    // [[1,0],[2,0],[3,1],[3,2]] -> [<1, 2>, <3>, <3>, <0>]
    for (int i = 0; i < (int)prerequisites.size(); ++i) {
      const auto& edge = prerequisites[i];
      
      if (graph[edge.first] == nullptr) {
        graph[edge.first] = new GraphNode(edge.first);
      } if (graph[edge.second] == nullptr) {
        graph[edge.second] = new GraphNode(edge.second);
      }
      
      graph[edge.second]->m_edges.push_back(graph[edge.first]);
    }

    // Topologically sort the graph
    for (int i = 0; i < numCourses; ++i) {
      auto node = graph[i];
      if (node) {
        visit(node, ordering);
      } else {
        ordering.push_back(i);
      }
    }
    std::reverse(ordering.begin(), ordering.end());

    // Clean up and return
    for (auto& x : graph) delete x;
    return ordering;
  }
private:
  void visit(GraphNode* node, std::vector<int>& ordering) const {
    if (node->visited) return;
    node->visited = true;
    auto& edges = node->m_edges;
    for (int i = 0; i < (int)edges.size(); ++i) {
      visit(edges[i], ordering); 
    }
    ordering.push_back(node->m_value);
  }
};

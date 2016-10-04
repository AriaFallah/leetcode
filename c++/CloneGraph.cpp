// https://leetcode.com/problems/clone-graph/

/*
  Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

  OJ's undirected graph serialization:
  Nodes are labeled uniquely.

  We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
  As an example, consider the serialized graph {0,1,2#1,2#2,2}.

  The graph has a total of three nodes, and therefore contains three parts as separated by #.

  First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
  Second node is labeled as 1. Connect node 1 to node 2.
  Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

  Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
 */

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode*> neighbors;
  explicit UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
  UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    if (!node) return nullptr;
    unordered_map<int, UndirectedGraphNode*> visited;
    return clone(node, visited);
  }
private:
  UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& visited) {
    // return if dupe
    if (visited.find(node->label) != visited.end()) return visited[node->label];
    
    UndirectedGraphNode* cloned = new UndirectedGraphNode(node->label);
    visited[node->label] = cloned;
    for (auto const& neighbor : node->neighbors) {
      if (node->label == neighbor->label) {
        // if cycle, push back same node
        cloned->neighbors.push_back(cloned); 
      } else if (visited.find(neighbor->label) != visited.end()) {
        // if node in neighbors already exists, push back existing node
        cloned->neighbors.push_back(visited[neighbor->label]); 
      } else {
        // otherwise, clone neighbor
        cloned->neighbors.push_back(clone(neighbor, visited)); 
      }
    }
    return cloned;
  }
};


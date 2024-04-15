#include "header.h"

class Node {
 public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  void getVertex(Node *node, unordered_set<Node *> &vertexs) {
    if (vertexs.find(node) == vertexs.end()) {
      vertexs.insert(node);
      for (auto neighbour : node->neighbors) {
        getVertex(neighbour, vertexs);
      }
    }
  }

 public:
  Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }
    unordered_set<Node *> oldvs;
    getVertex(node, oldvs);
    unordered_map<Node *, Node *> mp;
    for (auto p : oldvs) {
      mp.emplace(p, new Node(p->val));  // clone vertexs
    }
    // build edges
    for (auto p : oldvs) {
      Node *cloned = mp[p];
      int size = p->neighbors.size();
      cloned->neighbors.resize(size);
      for (int i = 0; i < size; ++i) {
        cloned->neighbors[i] = mp[p->neighbors[i]];
      }
    }
    return mp[node];
  }
};
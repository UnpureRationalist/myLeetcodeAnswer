#include "header.h"

class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    int n = profits.size();
    vector<pair<int, int>> products;
    products.reserve(n);
    for (int i = 0; i < n; ++i) {
      products.emplace_back(capital[i], profits[i]);
    }
    sort(products.begin(), products.end());
    int idx = 0;
    priority_queue<int, vector<int>, less<int>> q;
    while (k--) {
      while (idx < n && w >= products[idx].first) {
        q.push(products[idx].second);
        ++idx;
      }
      if (!q.empty()) {
        w += q.top();
        q.pop();
      } else {
        break;
      }
    }
    return w;
  }
};

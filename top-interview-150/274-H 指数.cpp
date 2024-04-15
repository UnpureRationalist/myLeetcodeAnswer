#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int n = citations.size();
    for (int i = n - 1; i >= 0; --i) {
      if (citations[i] >= i + 1) {
        return i + 1;
      }
    }
    return 0;
  }
};

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int h = 0, i = citations.size() - 1;
    while (i >= 0 && citations[i] > h) {
      h++;
      i--;
    }
    return h;
  }
};

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size(), tot = 0;
    vector<int> counter(n + 1);
    for (int i = 0; i < n; i++) {
      if (citations[i] >= n) {
        counter[n]++;
      } else {
        counter[citations[i]]++;
      }
    }
    for (int i = n; i >= 0; i--) {
      tot += counter[i];
      if (tot >= i) {
        return i;
      }
    }
    return 0;
  }
};

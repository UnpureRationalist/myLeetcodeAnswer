#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class RandomizedSet {
 public:
  RandomizedSet() { srand((unsigned)time(NULL)); }

  bool insert(int val) {
    if (val2idx.find(val) != val2idx.end()) {
      return false;
    }
    int idx = values.size();
    values.emplace_back(val);
    val2idx[val] = idx;
    return true;
  }

  bool remove(int val) {
    if (val2idx.find(val) == val2idx.end()) {
      return false;
    }
    int idx = val2idx[val];
    values[idx] = values.back();
    val2idx[values.back()] = idx;  // update idx
    values.pop_back();
    val2idx.erase(val);
    return true;
  }

  int getRandom() { return values[rand() % values.size()]; }

 private:
  vector<int> values;
  unordered_map<int, int> val2idx;
};

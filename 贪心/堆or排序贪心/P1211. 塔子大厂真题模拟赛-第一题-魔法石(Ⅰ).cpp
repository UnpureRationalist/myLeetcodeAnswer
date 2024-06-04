#include <bits/stdc++.h>
using namespace std;

struct Stone {
  int origin{0};
  int after{0};
  int differ{0};

  void calDiffer() { differ = after - origin; }

  bool deserveLighten() const { return after > origin; }
};

pair<vector<Stone>, long long> getDeserveLighten(const vector<Stone> &stones) {
  long long sum = 0;
  vector<Stone> ans;
  for (const auto &stone : stones) {
    if (stone.deserveLighten()) {
      ans.emplace_back(stone);
    } else {
      sum += stone.origin;
    }
  }
  return {ans, sum};
}

long long getMaxPrice(int m, const vector<Stone> &stones) {
  auto [ligntenStones, sum] = getDeserveLighten(stones);
  sort(ligntenStones.begin(), ligntenStones.end(),
       [](const auto &lop, const auto &rop) { return lop.differ > rop.differ; });
  int size = ligntenStones.size();
  for (int i = 0; i < size; ++i) {
    if (i < m) {
      sum += ligntenStones[i].after;
    } else {
      sum += ligntenStones[i].origin;
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<Stone> stones(n);
  for (int i = 0; i < n; ++i) {
    cin >> stones[i].origin;
  }
  for (int i = 0; i < n; ++i) {
    cin >> stones[i].after;
    stones[i].calDiffer();
  }
  cout << getMaxPrice(m, stones) << endl;
  return 0;
}

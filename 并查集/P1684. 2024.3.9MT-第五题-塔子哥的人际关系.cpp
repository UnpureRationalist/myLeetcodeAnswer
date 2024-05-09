#include <bits/stdc++.h>
using namespace std;

class UnionFindSetBigRange {
 public:
  UnionFindSetBigRange() = default;

  void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa != pb) {
      parents[pa] = pb;
    }
  }

  int Find(int x) { return parents.count(x) ? parents[x] = Find(parents[x]) : x; }

 private:
  unordered_map<int, int> parents;
};

int main() {
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  set<pair<int, int>> friends;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    friends.insert({a, b});
  }
  vector<tuple<int, int, int>> operations;
  while (q--) {
    int op, a, b;
    cin >> op >> a >> b;
    operations.emplace_back(op, a, b);
    if (op == 1) {
      friends.erase({a, b});
    }
  }
  UnionFindSetBigRange ufs;
  for (const auto &[x, y] : friends) {
    ufs.Union(x, y);
  }
  vector<char> answers;
  for (int i = operations.size() - 1; i >= 0; --i) {
    auto &[op, x, y] = operations[i];
    if (op == 1) {
      ufs.Union(x, y);
    } else {
      answers.emplace_back(ufs.Find(x) == ufs.Find(y));
    }
  }
  for (auto iter = answers.rbegin(); iter != answers.rend(); ++iter) {
    cout << (*iter ? "Yes" : "No") << "\n";
  }
  return 0;
}

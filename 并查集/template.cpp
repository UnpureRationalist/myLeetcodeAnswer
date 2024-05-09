#include <bits/stdc++.h>
using namespace std;

class UnionFindSet {
 public:
  explicit UnionFindSet(int n) {
    parents.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      parents[i] = i;
    }
  }

  void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa != pb) {
      parents[pa] = pb;
    }
  }

  int Find(int x) {
    if (parents[x] != x) {
      parents[x] = Find(parents[x]);
    }
    return parents[x];
  }

 private:
  vector<int> parents;  // parents[i] 表示 i 的父节点是 parents[i]，只能存储大于等于 0 的有限范围数字
};

// 扩大数据范围：数据范围变成了 10^9，因此需要对元素做一个离散化处理，直接使用哈希表来离散化即可
class UnionFindSetBigRange {
 public:
  UnionFindSetBigRange() = default;

  int Find(int x) { return parents.count(x) ? parents[x] = Find(parents[x]) : x; }

  void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa != pb) {
      parents[pa] = pb;
    }
  }

 private:
  unordered_map<int, int> parents;
};

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  UnionFindSetBigRange ufs;
  for (int i = 0; i < m; ++i) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'M') {
      ufs.Union(a, b);
    } else {
      bool ans = ufs.Find(a) == ufs.Find(b);
      cout << (ans ? "Yes" : "No") << "\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2E6 + 10, M = 1E6 + 10;

int n, w[N], prime_max[N], primes[M], cnt, k;

bool st[M];

void init() {
  for (int i = 2; i < M; i++)  // 埃氏筛质数
  {
    if (st[i]) {
      continue;
    }
    primes[cnt++] = i;
    for (int j = i * 2; j < M; j += i) {
      st[j] = true;
    }
  }
  prime_max[1] = 1;
  for (int i = 0; i < cnt; i++)  // 用质数更新 1e6 的数的最大质因子
  {
    int x = primes[i];
    for (int j = x; j < N; j += x) {
      prime_max[j] = max(prime_max[j], x);  // 用当前质数更新 j 的最大质因子
    }
  }
}

struct node {
  int x, id;
  friend bool operator<(const node &a, const node &b) {
    return a.x - a.x / prime_max[a.x] < b.x - b.x / prime_max[b.x];  // 大根堆
  }
};

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }

  init();

  priority_queue<node> heap;
  for (int i = 1; i <= n; i++) {
    if (w[i] > 1) {
      heap.push({w[i], i});
    }
  }

  while (heap.size() && k--) {
    auto t = heap.top();
    heap.pop();
    int val = t.x;
    val /= prime_max[val];
    w[t.id] = val;
    if (val > 1) {
      heap.push({val, t.id});
    }
  }

  ll res = accumulate(w + 1, w + n + 1, 0ll);
  cout << res << endl;
  return 0;
}

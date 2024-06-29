#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3E5 + 10, mod = 1e9 + 7;

int n, fact[N], infact[N];

unordered_map<string, int> cnts;  // 统计每个单词出现的次数

unordered_map<int, int> counts;  // 统计每个单词长度出现的次数

ll qmi(ll a, ll b, ll p) {
  ll res = 1, t = a;
  while (b) {
    if (b & 1) res = (res * t) % p;
    t = (t * t) % p;
    b >>= 1;
  }
  return res;
}

void init() {
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (ll)fact[i - 1] * i % mod;
    infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
  }
}

int main() {
  ios::sync_with_stdio(false);
  init();
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cnts[s]++;
    counts[(int)s.size()]++;
  }
  unordered_map<int, vector<int>> mp;  // 统计每个长度重复单词出现的个数
  for (auto &[u, v] : cnts) {
    if (v == 1) continue;
    int m = u.size();
    mp[m].push_back(v);
  }
  ll res = 1;
  for (auto &[u, v] : counts) {
    res = (res * fact[v]) % mod;
    for (int &x : mp[u]) res = (res * infact[x]) % mod;
  }
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> getModKMap(int n, int k, const string &s) {
  unordered_map<int, string> ans;
  for (int i = 0; i < n; ++i) {
    ans[i % k].push_back(s[i]);
  }
  return ans;
}

bool check(int n, int k, string &s, string &t) {
  auto smp = getModKMap(n, k, s);
  auto tmp = getModKMap(n, k, t);
  for (int i = 0; i < k; ++i) {
    sort(smp[i].begin(), smp[i].end());
    sort(tmp[i].begin(), tmp[i].end());
    if (smp[i] != tmp[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if (check(n, k, s, t)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isMHY(const string &s) {
  int n = s.length();
  if (n % 3) {
    return false;
  }
  for (int i = 0; i < n; i += 3) {
    if (s.substr(i, 3) != "mhy") {
      return false;
    }
  }
  return true;
}

bool legal(const string &s, const string &t) {
  int m = s.length();
  int n = t.length();
  int i = 0;
  int j = 0;
  string more;
  while (i < m && j < n) {
    if (s[i] == t[j]) {
      ++i;
      ++j;
    } else {
      more.push_back(t[j]);
      ++j;
    }
  }
  if (i != m) {
    return false;
  }

  return isMHY(more);
}

void solve() {
  string s;
  string target;
  cin >> s >> target;
  if (s.length() > target.length()) {
    swap(s, target);  // 短的为 s， 长的为 target
  }
  bool ok = legal(s, target);
  cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

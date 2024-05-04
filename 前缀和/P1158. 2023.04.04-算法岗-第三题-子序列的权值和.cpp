#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> get2powArray(int n) {
  vector<int> ans(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    ans[i] = (2 * ans[i - 1]) % MOD;
  }
  return ans;
}

void solve(const string &str) {
  int n = str.length();
  auto pow2array = get2powArray(n);
  // 预处理字母 d 后缀和的方案数
  vector<int> postNumD(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    postNumD[i] += postNumD[i + 1];
    if (str[i] == 'd') {
      postNumD[i] = (postNumD[i] + pow2array[n - i - 1]) % MOD;  // n-i-1个数 选或不选都可以
    }
  }
  long long preNumR = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'r') {
      preNumR = (preNumR + pow2array[i]) % MOD;
    } else if (str[i] == 'e') {
      ans = (ans + (preNumR * postNumD[i]) % MOD) % MOD;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  solve(s);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 10, mod = 1e9 + 7;

bool st[N];
int n, diff[N], b[N], c[N];  // b[i]表示当前数字i是否为质数(true表示不是质数) c[i]表示数字i可以拆分的质因子数量

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    diff[0]++;
    diff[x + 1]--;
  }
  long long res = 1;
  for (int i = 1; i < N; i++) {
    diff[i] += diff[i - 1];
  }
  for (int i = 2; i < N; i++) {
    if (b[i] == 1) continue;  // 当前数字i不是质数，跳过
    long cur = 0;
    for (int j = i; j < N; j += i) {
      b[j] = 1;             // 埃氏筛质数的模版，筛一遍质数 比如利用2筛掉4 6 8 10...
      c[j] = c[j / i] + 1;  // 例如c[2]=c[1]+1=1,c[4]=c[2]+1=2,c[8]=c[4]+1=3,可以快速推导出对应值
      cur = (cur + 1ll * c[j] * diff[j]) % mod;
    }
    for (int j = i; j < N; j += i) {  // 初始化，下一轮循环还需要重新计算
      c[j] = 0;
    }
    res = (res * (cur + 1)) % mod;
  }
  cout << res << endl;
  return 0;
}

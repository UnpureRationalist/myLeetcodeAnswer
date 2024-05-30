#include <iostream>
using namespace std;

double dp[91];

int main() {
  double p;
  cin >> p;

  double cnt = 0;  // 记录总期望次数

  for (int i = 1; i < 90; i++) {
    dp[i] = (1 - dp[i - 1]) * p;
    cnt += dp[i] * i;
    dp[i] += dp[i - 1];  // 前缀和
  }

  cnt += 90 * (1 - dp[89]);  // i = 90时特殊处理
  cout << fixed;
  cout.precision(7);
  cout << cnt * 1.5 << "\n";

  return 0;
}

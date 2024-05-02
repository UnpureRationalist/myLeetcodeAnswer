#include <iostream>
using namespace std;

const int N = 1e+6 + 10;

int a[N], S[N], n, m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {  // 下标从 1 开始
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {  // 下标从 1 开始
    S[i] = S[i - 1] + a[i];
  }
  while (m--) {
    int l;
    int r;
    cin >> l >> r;
    printf("%d\n", S[r] - S[l - 1]);  // 利用前缀和计算区间和
  }
  return 0;
}

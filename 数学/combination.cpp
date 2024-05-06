#include <iostream>
using namespace std;

const int n = 60;
long long combinationRes[n][n] = {0};

long long combination(long long n, long long m) {
  if (m == 0 || m == n) {
    return 1;
  }
  if (combinationRes[n][m] != 0) {
    return combinationRes[n][m];
  }
  return combinationRes[n][m] = combination(n - 1, m) + combination(n - 1, m - 1);
}

// 另一种实现
long long combination2(long long n, long long m) {
  long long ans = 1;
  for (long long i = 1; i <= m; ++i) {
    ans = ans * (n - m + i) / i;  // 先乘后除
  }
  return ans;
}

// 求 C_n^m mod p 结果
long long combination(long long n, long long m, long long p) {
  if (m == 0 || m == n) {
    return 1;
  }
  if (combinationRes[n][m] != 0) {
    return combinationRes[n][m];
  }
  return combinationRes[n][m] = (combination(n - 1, m) + combination(n - 1, m - 1)) % p;
}

void Test1() {
  int n = 10;
  int m = 5;
  cout << combination(n, m) << endl;
  cout << combination2(n, m) << endl;
}

int main() {
  Test1();
  return 0;
}
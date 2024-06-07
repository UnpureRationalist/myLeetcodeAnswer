/**
 * @file template.cpp
 * @author your name (you@domain.com)
 * @brief 求 1 ~ n 中质数的数量
 * @version 0.1
 * @date 2024-06-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (st[i]) {
      continue;
    }
    primes[cnt++] = i;
    for (int j = i + i; j <= n; j += i) {
      st[j] = true;
    }
  }
}

int main() {
  int n;
  cin >> n;

  get_primes(n);

  cout << cnt << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

char arr[3] = {'r', 'e', 'd'};

bool lessEqualThan(long long n, long long k) { return n >= (k * (k + 1) / 2); }

// 返回 k 使得 k*(k+1)/2 最大 且 小于等于 n
int check(int n) {
  long long left = 0;
  long long right = n;
  while (left <= right) {
    long long mid = left + (right - left) / 2;
    bool ok = lessEqualThan(n, mid);
    if (ok && !lessEqualThan(n, mid + 1)) {
      return mid;
    }
    if (ok) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

void solve(int n) {
  int idx = 0;
  while (n > 0) {
    int len = check(n);
    for (int i = 0; i < len; ++i) {
      cout << arr[idx];
    }
    idx = (idx + 1) % 3;
    n -= len * (len + 1) / 2;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  solve(n);
  return 0;
}

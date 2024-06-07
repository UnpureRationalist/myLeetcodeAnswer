#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeTable(int n) {
  if (n < 2) {
    return {};
  }
  vector<int> primes;
  vector<char> flags(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    if (flags[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= n; j += i) {
        flags[j] = false;
      }
    }
  }
  return primes;
}

int solve(int n) {
  vector<int> primes = getPrimeTable(n);  // 从小到大排列 2，3，5，7，...
  int num_primes = primes.size();
  if (num_primes == 0) {
    return 0;
  }
  int ans = 1;  // 2, 2, 2
  for (int i = 1; i < num_primes; ++i) {
    int sum = primes[i] + 2;
    int temp = sqrt(sum);
    if (temp * temp == sum) {
      bool found = binary_search(primes.begin(), primes.end(), temp);
      if (found) {
        ans += 2;
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}

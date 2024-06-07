#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeTable(int n, int count) {
  if (n < 2) {
    return {};
  }
  vector<int> primes;
  vector<char> flags(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    if (flags[i]) {
      primes.push_back(i);
      if (primes.size() >= count) {
        break;
      }
      for (int j = i + i; j <= n; j += i) {
        flags[j] = false;
      }
    }
  }
  return primes;
}

int solve(int n) {
  auto primes_lst = getPrimeTable(5e5, n);
  unordered_set<int> primes(primes_lst.begin(), primes_lst.end());
  int left = n;
  int count = 0;
  list<int> people;
  for (int i = 1; i <= n; ++i) {
    people.push_back(i);
  }
  while (left > 1) {
    for (auto iter = people.begin(); iter != people.end();) {
      ++count;
      if (primes.count(count)) {
        iter = people.erase(iter);
        left--;
      } else {
        ++iter;
      }
    }
  }
  return *people.begin();
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}

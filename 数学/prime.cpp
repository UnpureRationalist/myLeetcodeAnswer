#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 判断是否为素数
bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  int sqr = sqrt(1.0 * n);
  for (int i = 2; i <= sqr; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// 素数表
vector<int> primeTable(int n) {
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

// 质因子分解
struct Factor {
  int x;
  int cnt;

  Factor() = default;

  Factor(int _x, int _cnt) : x(_x), cnt(_cnt) {}
};

vector<Factor> primeFactors(int n, const vector<int> &primes) {
  vector<Factor> factors;
  int sqr = sqrt(1.0 * n);
  for (int i = 0; i < primes.size() && primes[i] <= sqr; ++i) {
    if (n % primes[i] == 0) {
      factors.emplace_back(primes[i], 0);
      while (n % primes[i] == 0) {
        factors.back().cnt++;
        n /= primes[i];
      }
    }
    if (n == 1) {
      break;
    }
  }
  if (n != 1) {
    factors.emplace_back(n, 1);
  }
  return factors;
}

// n 的因子个数
int numofFactors(const vector<Factor> &factors) {
  int ans = 1;
  for (auto &[_, cnt] : factors) {
    ans *= cnt + 1;
  }
  return ans;
}

// n 的所有因子之和
int sumofFactors(const vector<Factor> &factors) {
  int ans = 1;
  for (const auto &[prime, cnt] : factors) {
    int temp = 1;
    int sum = 0;
    for (int i = 0; i <= cnt; ++i) {
      sum += temp;
      temp *= prime;
    }
    ans *= sum;
  }
  return ans;
}

void show(const vector<Factor> &factors) {
  int n = factors.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << "*";
    }
    cout << factors[i].x;
    if (factors[i].cnt > 1) {
      cout << "^" << factors[i].cnt;
    }
  }
  cout << endl;
}

void Test1() {
  vector<int> nums = {1, 2, 3, 4, 5, 7, 9, 12, 13, 19};
  for (auto &num : nums) {
    cout << num << (isPrime(num) ? " is" : " is not") << " a prime." << endl;
  }
}

void Test2() {
  int n = 100;
  vector<int> nums = primeTable(n);
  for (const auto &num : nums) {
    cout << num << " ";
  }
  cout << endl;
}

void Test3() {
  int n = 180;
  vector<int> primes = primeTable(n);
  vector<Factor> factors = primeFactors(n, primes);
  show(factors);
  cout << n << " has " << numofFactors(factors) << " factors." << endl;
  cout << n << " sum of factors is " << sumofFactors(factors) << endl;

  n = 100;
  factors = primeFactors(n, primes);
  show(factors);
  cout << n << " has " << numofFactors(factors) << " factors." << endl;
  cout << n << " sum of factors is " << sumofFactors(factors) << endl;

  n = 125;
  factors = primeFactors(n, primes);
  show(factors);
  cout << n << " has " << numofFactors(factors) << " factors." << endl;
  cout << n << " sum of factors is " << sumofFactors(factors) << endl;
}

int main() {
  Test1();
  Test2();
  Test3();
  return 0;
}
#include <iostream>
using namespace std;

// 求 n! 有多少个质因子 p
int primeFactorsOfFactorial(int n, int p) {
  int ans = 0;
  while (n) {
    n /= p;
    ans += n;
  }
  return ans;
}

// 递归版本
int primeFactorsOfFactorialRecursion(int n, int p) {
  if (n < p) {
    return 0;
  }
  return n / p + primeFactorsOfFactorial(n / p, p);
}

void Test1() {
  int n = 10;
  int p = 2;
  cout << n << "!"
       << " has " << primeFactorsOfFactorial(n, p) << " prime factor " << p << endl;
  cout << n << "!"
       << " has " << primeFactorsOfFactorialRecursion(n, p) << " prime factor " << p << endl;
}

int main() {
  Test1();
  return 0;
}

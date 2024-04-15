class Solution {
 public:
  double myPow(double x, long long n) {
    if (n < 0) {
      return 1.0 / myPow(x, -n);
    }
    if (n == 0) {
      return 1.0;
    }
    if (n & 1) {
      return x * myPow(x, n - 1);
    }
    double temp = myPow(x, n / 2);
    return temp * temp;
  }
};

class Solution {
 public:
  double quickMul(double x, long long n) {
    double ans = 1.0;
    // 贡献的初始值为 x
    double x_contribute = x;
    // 在对 N 进行二进制拆分的同时计算答案
    while (n > 0) {
      if (n % 2 == 1) {
        // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
        ans *= x_contribute;
      }
      // 将贡献不断地平方
      x_contribute *= x_contribute;
      // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
      n /= 2;
    }
    return ans;
  }

  double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
  }
};

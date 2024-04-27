#include "header.h"

class Solution {
  int numberOf1(const char *str) {
    if (*str == '\0') {
      return 0;
    }

    int first = *str - '0';
    int length = strlen(str);

    if (length == 1 && first == 0) {
      return 0;  // str = "0"
    }
    if (length == 1 && first > 0) {
      return 1;  // str = "1" ~ "9" [1, 9] 个位数
    }
    // 假设 str = "21345"
    int numFirstDigit = 0;  // 表示 10000 ~ 19999 第一位中 1 的数量
    if (first > 1) {
      numFirstDigit = pow(10, length - 1);
    } else if (first == 1) {
      numFirstDigit = atoi(str + 1) + 1;
    }

    int numOtherDigits = first * (length - 1) * pow(10, length - 2);  // 1346 ~ 21345 除第一位之外的数位中 1 的数量
    int numRecursive = numberOf1(str + 1);
    return numFirstDigit + numOtherDigits + numRecursive;
  }

 public:
  int countDigitOne(int n) {
    string str = to_string(n);
    return numberOf1(str.c_str());
  }
};

class Solution {
 public:
  int countDigitOne(int n) {
    // mulk 表示 10^k
    // 在下面的代码中，可以发现 k 并没有被直接使用到（都是使用 10^k）
    // 但为了让代码看起来更加直观，这里保留了 k
    long long mulk = 1;
    int ans = 0;
    for (int k = 0; n >= mulk; ++k) {
      ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
      mulk *= 10;
    }
    return ans;
  }
};

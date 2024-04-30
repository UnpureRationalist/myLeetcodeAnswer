#include "header.h"

class Solution {
 public:
  int encryptionCalculate(int dataA, int dataB) {
    int sum = 0;
    int carry = 0;
    do {
      sum = dataA ^ dataB;
      carry = (dataA & dataB) << 1;  // 由于是进位，因此每次循环都要左移一位
      dataA = sum;
      dataB = carry;
    } while (dataB != 0);
    return dataA;
  }
};

// 递归简洁版本
class Solution {
 public:
  int encryptionCalculate(int a, int b) {
    if (b == 0) {
      return a;
    }

    // 转换成非进位和 + 进位
    return encryptionCalculate(a ^ b, (a & b) << 1);
  }
};

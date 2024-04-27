#include "header.h"

class Solution {
  long long countOfInteges(int digits) {
    if (digits == 1) {
      return 10;
    }
    int count = static_cast<int>(pow(10, digits - 1));
    return 9 * count;
  }

  int beginNumber(int digits) {
    if (digits == 1) {
      return 0;
    }
    return pow(10, digits - 1);
  }

  int digitAtIndex(int index, int digits) {
    int number = beginNumber(digits) + index / digits;
    int indexFromRight = digits - index % digits;
    for (int i = 1; i < indexFromRight; ++i) {
      number /= 10;
    }
    return number % 10;
  }

 public:
  int findNthDigit(long long n) {
    if (n < 0) {
      return -1;
    }
    int digits = 1;
    while (true) {
      long long numbers = countOfInteges(digits);
      if (n < numbers * digits) {
        return digitAtIndex(n, digits);
      }
      n -= digits * numbers;
      ++digits;
    }
    return -1;
  }
};

// 二分查找
class Solution {
 public:
  int findNthDigit(int n) {
    int low = 1, high = 9;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (totalDigits(mid) < n) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    int d = low;
    int prevDigits = totalDigits(d - 1);
    int index = n - prevDigits - 1;
    int start = (int)pow(10, d - 1);
    int num = start + index / d;
    int digitIndex = index % d;
    int digit = (num / (int)(pow(10, d - digitIndex - 1))) % 10;
    return digit;
  }

  int totalDigits(int length) {
    int digits = 0;
    int curLength = 1, curCount = 9;
    while (curLength <= length) {
      digits += curLength * curCount;
      curLength++;
      curCount *= 10;
    }
    return digits;
  }
};

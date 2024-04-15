#include "header.h"

class Solution {
  int getSquareSum(int n) {
    int sum = 0;
    while (n) {
      int temp = n % 10;
      n /= 10;
      sum += temp * temp;
    }
    return sum;
  }

 public:
  bool isHappy(int n) {
    unordered_set<int> hash;
    while (n != 1) {
      if (hash.find(n) != hash.end()) {
        return false;
      }
      hash.insert(n);
      n = getSquareSum(n);
    }
    return true;
  }
};

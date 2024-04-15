#include "header.h"

bool isPrime(int n) {
  if (n == 2) {
    return true;
  }
  for (int i = 2; i * i <= n; ++i) {
    if ((n % i) == 0) {
      return false;
    }
  }
  return true;
}

class Solution {
  unordered_set<int> getPrime() {
    unordered_set<int> st;
    for (int i = 2; i <= 100; ++i) {
      if (isPrime(i)) {
        st.insert(i);
      }
    }
    return st;
  }

 public:
  int maximumPrimeDifference(vector<int> &nums) {
    unordered_set<int> st = getPrime();
    int n = nums.size();
    int start_idx = -1;
    for (int i = 0; i < n; ++i) {
      if (st.find(nums[i]) != st.end()) {
        start_idx = i;
        break;
      }
    }
    int end_idx = -1;
    for (int i = n - 1; i >= start_idx; --i) {
      if (st.find(nums[i]) != st.end()) {
        end_idx = i;
        break;
      }
    }
    return end_idx - start_idx;
  }
};

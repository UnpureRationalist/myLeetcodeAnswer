#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n, 1);
    for (int i = 1; i < n; ++i) {
      if (ratings[i - 1] < ratings[i]) {
        left[i] = left[i - 1] + 1;
      }
    }
    int right = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (i < n - 1 && ratings[i] > ratings[i + 1]) {
        ++right;
      } else {
        right = 1;
      }
      ans += max(left[i], right);
    }
    return ans;
  }
};

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] >= ratings[i - 1]) {
        dec = 0;
        pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
        ret += pre;
        inc = pre;
      } else {
        dec++;
        if (dec == inc) {
          dec++;
        }
        ret += dec;
        pre = 1;
      }
    }
    return ret;
  }
};

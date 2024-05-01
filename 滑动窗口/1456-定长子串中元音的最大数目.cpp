#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_set<char> charsets{'a', 'e', 'i', 'o', 'u'};

 public:
  int maxVowels(string s, int k) {
    int n = s.length();
    int ans = 0;
    int num = 0;
    for (int i = 0; i < k - 1; ++i) {
      if (charsets.find(s[i]) != charsets.end()) {
        ++num;
      }
    }
    for (int i = 0; i <= n - k; ++i) {
      int r = i + k - 1;
      if (charsets.find(s[r]) != charsets.end()) {
        ++num;
      }
      ans = max(ans, num);
      if (charsets.find(s[i]) != charsets.end()) {
        --num;
      }
    }
    return ans;
  }
};

// 写法 2
class Solution {
 public:
  int maxVowels(string s, int k) {
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
    int res = 0, n = s.size();
    for (int l = 0, r = 0, num = 0; r < n; r++) {
      if (st.count(s[r])) {
        num++;
      }
      while (r - l + 1 > k) {  // 如果区间长度大于 k，移动左指针
        if (st.count(s[l])) {
          num--;
        }
        l++;
      }
      res = max(res, num);
    }
    return res;
  }
};

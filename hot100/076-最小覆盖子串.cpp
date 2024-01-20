#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    int m = s.length();
    int n = t.length();
    if (m < n) {
      return "";
    }

    unordered_map<char, int> s_hash, t_hash;

    for (auto &c : t) {
      t_hash[c]++;
    }

    string res;
    int minLength = INT32_MAX;
    int cnt = 0;

    for (int i = 0, j = 0; i < m; i++) {
      s_hash[s[i]]++;
      if (s_hash[s[i]] <= t_hash[s[i]]) cnt++;

      // 如果有效字符的个数与t的长度一样，说明此时j ~ i 包含了t
      if (cnt == n) {
        // 此时需要移动j，找到以i结尾的最小的包含t的串
        // 如果j对应的这个字符是一个冗余的字符，需要移动j
        while (s_hash[s[j]] > t_hash[s[j]]) {
          s_hash[s[j]]--;
          j++;
        }

        if (i - j + 1 < minLength) {
          res = s.substr(j, i - j + 1);
          minLength = res.size();
        }
      }
      // 继续查看下一个以i结尾包含t的长度最小的字串
    }

    return res;
  }
};
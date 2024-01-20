#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int sLen = s.size(), pLen = p.size();

    if (sLen < pLen) {
      return vector<int>();
    }

    vector<int> ans;
    vector<int> sCount(26);
    vector<int> pCount(26);
    for (int i = 0; i < pLen; ++i) {
      ++sCount[s[i] - 'a'];
      ++pCount[p[i] - 'a'];
    }

    if (sCount == pCount) {
      ans.emplace_back(0);
    }

    for (int i = 0; i < sLen - pLen; ++i) {
      --sCount[s[i] - 'a'];
      ++sCount[s[i + pLen] - 'a'];

      if (sCount == pCount) {
        ans.emplace_back(i + 1);
      }
    }

    return ans;
  }
};

class Solution2 {
 public:
  vector<int> findAnagrams(string s, string p) {
    int sLen = s.size(), pLen = p.size();

    if (sLen < pLen) {
      return vector<int>();
    }

    vector<int> ans;
    vector<int> count(26);
    for (int i = 0; i < pLen; ++i) {
      ++count[s[i] - 'a'];
      --count[p[i] - 'a'];
    }

    int differ = 0;
    for (int j = 0; j < 26; ++j) {
      if (count[j] != 0) {
        ++differ;
      }
    }

    if (differ == 0) {
      ans.emplace_back(0);
    }

    for (int i = 0; i < sLen - pLen; ++i) {
      if (count[s[i] - 'a'] ==
          1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
        --differ;
      } else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p
                                            // 中的数量从相同变得不同
        ++differ;
      }
      --count[s[i] - 'a'];

      if (count[s[i + pLen] - 'a'] ==
          -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
        --differ;
      } else if (count[s[i + pLen] - 'a'] ==
                 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p
                       // 中的数量从相同变得不同
        ++differ;
      }
      ++count[s[i + pLen] - 'a'];

      if (differ == 0) {
        ans.emplace_back(i + 1);
      }
    }

    return ans;
  }
};

class Solution3 {
 public:
  vector<int> findAnagrams(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    vector<int> res;  // 记录结果
    while (right < s.size()) {
      char c = s[right];
      right++;
      // 进行窗口内数据的一系列更新
      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) valid++;
      }
      // 判断左侧窗口是否要收缩
      while (right - left >= t.size()) {
        // 当窗口符合条件时，把起始索引加入 res
        if (valid == need.size()) res.push_back(left);
        char d = s[left];
        left++;
        // 进行窗口内数据的一系列更新
        if (need.count(d)) {
          if (window[d] == need[d]) valid--;
          window[d]--;
        }
      }
    }
    return res;
  }
};

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
  string reverseWords(string s) {
    int n = s.length();
    string ans;
    ans.reserve(n);
    int i = n - 1;
    while (i >= 0) {
      while (i >= 0 && s[i] == ' ') {
        --i;
      }
      int j = i - 1;
      while (j >= 0 && s[j] != ' ') {
        --j;
      }
      if (i >= 0) {
        ans.append(s.substr(j + 1, i - j));
        ans.push_back(' ');
      }
      i = j;
    }
    return ans.substr(0, ans.length() - 1);
  }
};

class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start) {
      if (s[start] != ' ') {
        // 填一个空白字符然后将idx移动到下一个单词的开头位置
        if (idx != 0) {
          s[idx++] = ' ';
        }

        // 循环遍历至单词的末尾
        int end = start;
        while (end < n && s[end] != ' ') {
          s[idx++] = s[end++];
        }

        // 反转整个单词
        reverse(s.begin() + idx - (end - start), s.begin() + idx);

        // 更新start，去找下一个单词
        start = end;
      }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
  }
};

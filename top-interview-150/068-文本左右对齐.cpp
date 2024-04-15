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
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    int n = words.size();
    vector<string> result;
    int i = 0;
    while (i < n) {
      int len = words[i].length();
      int j = i + 1;
      while (j < n && len + 1 + words[j].length() <= maxWidth) {
        len += 1 + words[j].length();
        ++j;
      }
      string temp = words[i];
      temp.reserve(maxWidth + 1);
      if (j == n) {
        // 最后一行 左对齐
        for (int k = i + 1; k < j; ++k) {
          temp.push_back(' ');
          temp.append(words[k]);
        }
        temp.append(maxWidth - temp.length(), ' ');
      } else {
        // 两端对齐
        int words_len = 0;
        for (int k = i; k < j; ++k) {
          words_len += words[k].length();
        }
        int space_num = maxWidth - words_len;
        int num_words = j - i;
        // 将 space_num 个空格尽可能均匀分布在 num_words 个单词之间
        if (num_words == 1) {
          temp.append(space_num, ' ');
        } else {
          vector<int> spaces(num_words - 1, space_num / (num_words - 1));
          int left_spaces = space_num % (num_words - 1);
          for (int k = 0; k < left_spaces; ++k) {
            spaces[k] += 1;
          }
          for (int k = i + 1; k < j; ++k) {
            temp.append(spaces[k - i - 1], ' ');
            temp.append(words[k]);
          }
        }
      }
      result.emplace_back(std::move(temp));
      i = j;
    }
    return result;
  }
};

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
      std::hash<int> hasher;
      size_t seed = 0;
      for (int i : v) {
        seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
      return seed;
    }
  };

  vector<int> str2vector(const string& str) {
    vector<int> v(26, 0);
    for (auto c : str) {
      v[c - 'a']++;
    }
    return v;
  }

 public:
  /**
   * @brief
   * 依次对每个单词进行处理，首先需要判断：给定的一个单词是不是已经见过的单词的异位词
   * 若是：
   *     找到对应异位词在结果中的下标，并将此单词添加到 vector 末尾
   * 若不是：
   *     在 res 中新添加一个 vector，并记录此单词到 res 中的下标映射
   *
   * 问题 1：如何判断给定单词是否是已经见过的单词的异位词？
   *     使用数据结构 unordered_map<vector, int> 记录，表示异位词在 res 中的下标
   *     这里需要将 string 转换为一个 vector，vector 长度 26
   * ，每个位置表示字母数量
   *
   * @param strs
   * @return vector<vector<string>>
   */
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;

    unordered_map<string, int> hash;
    int idx = 0;
    for (const auto& str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      int pos = 0;
      if (hash.find(s) == hash.end()) {
        pos = idx;
        hash[s] = idx++;
        res.emplace_back(vector<string>{1, str});
      } else {
        pos = hash[s];
        res[pos].push_back(str);
      }
    }
    return res;
  }
};

// 官方题解
class Solution2 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      ans.emplace_back(it->second);
    }
    return ans;
  }
};
#include "header.h"

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    for (const auto &s : strs) {
      string temp = s;
      sort(temp.begin(), temp.end());
      mp[temp].push_back(s);
    }
    vector<vector<string>> res;
    res.reserve(mp.size());
    for (auto &[key, value] : mp) {
      res.emplace_back(std::move(value));
    }
    return res;
  }
};

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // 自定义对 array<int, 26> 类型的哈希函数
    auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t {
      return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) { return (acc << 1) ^ fn(num); });
    };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
    for (string &str : strs) {
      array<int, 26> counts{};
      int length = str.length();
      for (int i = 0; i < length; ++i) {
        counts[str[i] - 'a']++;
      }
      mp[counts].emplace_back(str);
    }
    vector<vector<string>> ans;
    ans.reserve(mp.size());
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      ans.emplace_back(std::move(it->second));
    }
    return ans;
  }
};

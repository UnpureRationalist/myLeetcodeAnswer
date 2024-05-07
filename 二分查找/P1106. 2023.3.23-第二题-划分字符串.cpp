#include <bits/stdc++.h>
using namespace std;

bool canSplit(const string &str, int k, int max_sub_len, long long weight) {
  // 采用贪心策略，使得字串权重小于等于 weight 情况下，长度尽可能大
  // 求出在当前 weight 和 max_sub_len 约束下，划分出的实际字符串数目是否小于等于 k
  long long n = str.length();
  vector<int> char2times(26, 0);
  int num_of_substr = 0;
  // 初始化 hashmap
  char2times[str[0] - 'a']++;
  int num_differ_chars = 1;
  for (long long i = 0, j = 0; j < n;) {
    while (j + 1 < n && (j - i + 1) * num_differ_chars < weight) {
      ++j;
      char2times[str[j] - 'a']++;
      if (char2times[str[j] - 'a'] == 1) {
        num_differ_chars++;
      }
    }
    // 如果字串权重大于 weight ，则将字符数减少 1
    if ((j - i + 1) * num_differ_chars > weight) {
      if (char2times[str[j] - 'a'] == 1) {
        num_differ_chars++;
      }
      char2times[str[j] - 'a']++;
      --j;
    }
    ++num_of_substr;
    // 更新子串下标位置等信息
    i = j + 1;
    j = j + 1;
    fill(char2times.begin(), char2times.end(), 0);
    char2times[str[i] - 'a']++;
    num_differ_chars = 1;
  }
  return num_of_substr <= k;
}

void solve(const string &str, int k) {
  int n = str.length();
  // 将长度为 n 的字符串划分为 k 个子串，则这 k 个字串中，最大字符串长度为 mas_sub_len
  int max_sub_len = n / k + 1;
  if (n % k == 0) {
    max_sub_len--;
  }
  long long ans = 0;

  long long left = max_sub_len;
  long long right = static_cast<long long>(max_sub_len) * max_sub_len;

  while (left <= right) {
    long long mid = left + (right - left) / 2;
    bool ok = canSplit(str, k, max_sub_len, mid);
    if (ok && (mid == max_sub_len || !canSplit(str, k, max_sub_len, mid - 1))) {
      ans = mid;
      break;
    }
    if (ok) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  string str;
  cin >> str;
  int k;
  cin >> k;
  solve(str, k);
  return 0;
}

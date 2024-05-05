#include <bits/stdc++.h>
using namespace std;

struct Duration {
  int start;
  int end;
};

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Duration> records(n);
  for (int i = 0; i < n; ++i) {
    cin >> records[i].start;
  }
  for (int i = 0; i < n; ++i) {
    cin >> records[i].end;
  }
  // 离散化差分
  map<int, int> mp;
  for (const auto &[start, end] : records) {
    mp[start]++;
    mp[end + 1]--;
  }
  unordered_map<int, int> cnts;  // 统计观测到流星的频数
  int sum = 0;
  int pre = min_element(records.begin(), records.end(), [](const Duration &lop, const Duration &rop) -> bool {
              return lop.start < rop.start;
            })->end;
  for (const auto &[key, value] : mp) {
    cnts[sum] += key - pre;
    sum += value;
    pre = key;
  }
  int max_cnt = 0;
  int max_num = 0;
  for (auto &[u, v] : cnts)  // 计算最多能观测的流星数量和频数
  {
    if (max_cnt < u) {
      max_cnt = u;
      max_num = v;
    }
  }
  cout << max_cnt << " " << max_num << endl;
  return 0;
}

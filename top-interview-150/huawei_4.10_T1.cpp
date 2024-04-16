#include <bits/stdc++.h>
using namespace std;

// client     <factor,  time>
map<string, unordered_map<string, int>> handleRecords(const vector<string> &records) {
  // 去重(日志中如果同一客户同一计费因子在相同时间戳上报多次话单只能计费一次)
  unordered_map<string, int> tsClientFactor2dur;
  for (auto &line : records) {
    int idx = line.find_last_of(',');
    string key = line.substr(0, idx);
    string value = line.substr(idx + 1);
    tsClientFactor2dur[key] = stoi(value);
  }
  map<string, unordered_map<string, int>> client2factor_time;
  for (const auto &[tsClientFactor, time] : tsClientFactor2dur) {
    int first_idx = tsClientFactor.find_first_of(',');
    int last_idx = tsClientFactor.find_last_of(',');
    string client = tsClientFactor.substr(first_idx + 1, last_idx - first_idx - 1);
    string factor = tsClientFactor.substr(last_idx + 1);
    client2factor_time[client][factor] += (time >= 0 && time <= 100) ? time : 0;
  }
  return client2factor_time;
}

unordered_map<string, int> handleFactors(const vector<string> &factors) {
  unordered_map<string, int> mp;
  for (auto &line : factors) {
    int idx = line.find_first_of(',');
    string key = line.substr(0, idx);
    string value = line.substr(idx + 1);
    mp[key] = stoi(value);
  }
  return mp;
}

void solve(const vector<string> &records, const vector<string> &factors) {
  auto client2factor_lst = handleRecords(records);
  auto factor2price = handleFactors(factors);
  for (const auto &[client, factor_lst] : client2factor_lst) {
    int sum = 0;
    for (auto &[factor, time] : factor_lst) {
      sum += time * factor2price[factor];
    }
    cout << client << "," << sum << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> records(n);
  for (int i = 0; i < n; ++i) {
    cin >> records[i];
  }
  int m;
  cin >> m;
  vector<string> factors(m);
  for (int i = 0; i < m; ++i) {
    cin >> factors[i];
  }
  solve(records, factors);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Plant {
  int time;
  int income;
};

int solve(int n, int m, const vector<Plant> &plants) {
  vector<int> dp(m + 1, 0);
  for (int i = 0; i < n; ++i) {
    int time = plants[i].time;
    int income = plants[i].income;
    for (int j = time; j <= m; ++j) {
      dp[j] = max(dp[j], dp[j - time] + income);
    }
  }
  return dp[m];
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;  // 作物种类数和游戏时长
  cin >> n >> m;
  vector<Plant> plants(n);
  for (int i = 0; i < n; ++i) {
    cin >> plants[i].time;
  }
  {
    vector<pair<int, int>> nums(n);

    for (int i = 0; i < n; ++i) {
      cin >> nums[i].first;
    }

    for (int i = 0; i < n; ++i) {
      cin >> nums[i].second;
      plants[i].income = nums[i].second - nums[i].first;
    }
  }
  cout << solve(n, m, plants) << endl;
  return 0;
}
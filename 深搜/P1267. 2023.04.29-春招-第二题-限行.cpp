#include <bits/stdc++.h>
using namespace std;

// 判断 cars 列表中的车是否能用于一周通行
bool canAccess(const vector<int> &cars, const vector<vector<char>> &accessible) {
  for (auto &access : accessible) {
    bool ok = false;
    for (auto &car : cars) {
      if (access[car]) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      return false;
    }
  }
  return true;
}

void dfs(int depth, int cars, const vector<vector<char>> &accessible, vector<int> &cars_lst, bool &ans) {
  if (ans) {
    return;
  }
  if (cars_lst.size() == cars) {
    if (canAccess(cars_lst, accessible)) {
      ans = true;
    }
    return;
  }
  if (depth == 10) {
    return;
  }
  // 选
  cars_lst.push_back(depth);
  dfs(depth + 1, cars, accessible, cars_lst, ans);
  cars_lst.pop_back();
  // 不选
  dfs(depth + 1, cars, accessible, cars_lst, ans);
}

// 判断买 cars 个车，能否一周内通行
bool check(int cars, const vector<vector<char>> &accessible) {
  vector<int> cars_lst;
  bool ans = false;
  dfs(0, cars, accessible, cars_lst, ans);
  return ans;
}

void solve(const vector<vector<char>> &accessible) {
  // 枚举买 cars 个车
  int left = 1;
  int right = 10;
  int ans = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    bool ok = check(mid, accessible);
    if (ok && (mid == 1 || !check(mid - 1, accessible))) {
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
  int days = 7;
  vector<vector<char>> accessible(days, vector<char>(10, 1));
  for (int i = 0; i < days; ++i) {
    int n;
    cin >> n;
    int temp;
    for (int j = 0; j < n; ++j) {
      cin >> temp;
      accessible[i][temp] = 0;
    }
  }
  solve(accessible);
  return 0;
}

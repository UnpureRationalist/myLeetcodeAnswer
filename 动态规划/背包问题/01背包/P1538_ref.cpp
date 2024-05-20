#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using vec = vector<int>;
using vv = vector<vector<int>>;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int sum = accumulate(arr.begin(), arr.end(), 0);
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
  vector<vv> path(n + 1, vv(sum + 1));

  int ans = sum, x = 0, y = 0;
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= sum; ++j) {
      if (dp[i - 1][j]) {
        path[i][j] = path[i - 1][j];
        dp[i][j] = dp[i - 1][j];
      } else if (j >= arr[i - 1]) {
        dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i - 1]];
        path[i][j] = path[i - 1][j - arr[i - 1]];
        if (dp[i][j]) {
          int c = abs(sum - 2 * j);
          path[i][j].push_back(i - 1);
          if (c < ans) {
            ans = c;
            x = i;
            y = j;
          }
        }
      }
    }
  }

  cout << ans << endl;
  vector<int> a = path[x][y], b;
  set<int> st(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (!st.count(i)) {
      b.push_back(i);
    }
  }
  vector<vector<int>> plan;
  for (size_t i = 0, j = 0; i < a.size() && j < b.size();) {
    int x = a[i], y = b[j];
    int vx = arr[x], vy = arr[y];
    plan.push_back({x + 1, y + 1});
    if (vx == vy) {
      ++i;
      ++j;
    } else if (vx < vy) {
      arr[y] -= arr[x];
      ++i;
    } else {
      arr[x] -= arr[y];
      ++j;
    }
  }
  cout << plan.size() << endl;
  for (auto e : plan) {
    cout << e[0] << " " << e[1] << endl;
  }
}

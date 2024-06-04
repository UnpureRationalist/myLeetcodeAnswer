#include <bits/stdc++.h>
using namespace std;

struct Task {
  int end_time;
  int income;
};

bool operator<(const Task &lop, const Task &rop) { return lop.end_time < rop.end_time; }

long long solve(int n, vector<Task> &tasks) {
  sort(tasks.begin(), tasks.end());                  // 按结束时间升序排序
  priority_queue<int, vector<int>, greater<int>> q;  // 小根堆
  for (int i = 0; i < n; ++i) {
    auto &[end_time, income] = tasks[i];
    if (q.size() < end_time) {
      q.emplace(income);
    } else {
      if (q.top() < income) {
        q.pop();
        q.emplace(income);
      }
    }
  }
  long long ans = 0;
  while (!q.empty()) {
    ans += q.top();
    q.pop();
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Task> tasks(n);
  for (auto &task : tasks) {
    cin >> task.end_time >> task.income;
  }
  cout << solve(n, tasks) << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1E5 + 10;
int n, f[N];

struct node {
  int end_time, income;
  bool operator<(const node &x) { return end_time < x.end_time; }
};

node a[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].end_time >> a[i].income;
  sort(a, a + n);
  priority_queue<int, vector<int>, greater<int>> heap;
  for (int i = 0; i < n; i++) {
    if (heap.size() < a[i].end_time)
      heap.push(a[i].income);
    else {
      if (heap.top() < a[i].income) {
        heap.pop();
        heap.push(a[i].income);
      }
    }
  }
  ll res = 0;
  while (heap.size()) {
    res += heap.top();
    heap.pop();
  }
  cout << res << endl;
  return 0;
}

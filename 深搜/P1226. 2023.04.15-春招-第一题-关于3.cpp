#include <bits/stdc++.h>
using namespace std;

vector<long long> getElements(long long x) {
  vector<long long> result;
  long long ans = 1;
  while (ans <= x) {
    result.push_back(ans);
    ans *= 3;
  }
  return result;
}

struct Node {
  bool plus{true};
  long long num{0};

  Node() = default;

  Node(bool _plus, int _num) : plus(_plus), num(_num) {}

  string ToString() const {
    if (plus) {
      return "+" + to_string(num);
    }
    return "-" + to_string(num);
  }

  bool operator<(const Node &rop) const { return num > rop.num; }
};

void dfs(long long x, const vector<long long> &nums, vector<Node> &result) {
  if (x == 0) {
    return;
  }
  if (result.size() >= 2) {
    int n = result.size();
    if (result[n - 1].num == result[n - 2].num) {
      return;
    }
  }
  if (x > 0) {
    auto iter = lower_bound(nums.begin(), nums.end(), x);
    if (iter == nums.end() || (*iter > x)) {
      --iter;
    }
    result.emplace_back(true, *iter);
    dfs(x - *iter, nums, result);
  } else {
    // 需要加上 1 个数
    int pos = -x;
    auto iter = lower_bound(nums.begin(), nums.end(), pos);
    if (iter == nums.end() || (*iter > pos)) {
      --iter;
    }
    result.emplace_back(false, *iter);
    dfs(x + *iter, nums, result);
  }
}

bool needContinue(vector<Node> &nums) {
  int n = nums.size();
  int i = 1;
  for (; i < n; ++i) {
    if (nums[i].num == nums[i - 1].num) {
      break;
    }
  }
  if (i == n) {
    return false;
  }

  // 更新 nums 数组
  while (nums.size() > i) {
    nums.pop_back();
  }
  bool plus = nums.back().plus;
  long long last = nums.back().num;
  nums.back() = Node(plus, last * 3);  // 赋予更大的值

  return true;
}

void print(vector<Node> &result) {
  int n = result.size();
  sort(result.begin(), result.end());
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      cout << result[i].num;
    } else {
      cout << result[i].ToString();
    }
  }
  cout << endl;
}

void solve(long long x) {
  vector<long long> nums = getElements(x);
  vector<Node> result;
  do {
    long long target = x;
    for (auto &[plus, num] : result) {
      if (plus) {
        target -= num;
      } else {
        target += num;
      }
    }
    dfs(target, nums, result);
  } while (needContinue(result));
  print(result);
}

int main() {
  ios::sync_with_stdio(false);
  long long x;
  cin >> x;
  solve(x);
  return 0;
}

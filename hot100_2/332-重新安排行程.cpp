#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  // unordered_map<出发城市, map<到达城市, 航班次数>> targets
  unordered_map<string, map<string, int>> targets;

  bool backtracking(int ticketNum, vector<string> &result) {
    if (result.size() == ticketNum + 1) {
      return true;
    }
    for (pair<const string, int> &target : targets[result.back()]) {
      if (target.second > 0) {
        result.push_back(target.first);
        target.second--;
        if (backtracking(ticketNum, result)) return true;
        result.pop_back();
        target.second++;
      }
    }
    return false;
  }

 public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    vector<string> result;
    for (const vector<string> &vec : tickets) {
      targets[vec[0]][vec[1]]++;  // 记录映射关系
    }
    result.push_back("JFK");
    backtracking(tickets.size(), result);
    return result;
  }
};

class Solution {
  unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

  vector<string> stk;

  void dfs(const string &curr) {
    while (vec.count(curr) && vec[curr].size() > 0) {
      string tmp = vec[curr].top();
      vec[curr].pop();
      dfs(move(tmp));
    }
    stk.emplace_back(curr);
  }

 public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    for (auto &it : tickets) {
      vec[it[0]].emplace(it[1]);
    }
    dfs("JFK");

    reverse(stk.begin(), stk.end());
    return stk;
  }
};

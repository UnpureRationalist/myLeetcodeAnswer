#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  struct WindowValues {
    map<int, int> mp;  // key and it appear times

    void Insert(int key) { mp[key]++; }

    void Remove(int key) {
      auto iter = mp.find(key);
      if (iter != mp.end()) {
        if (iter->second == 1) {
          mp.erase(iter);
        } else {
          (iter->second)--;
        }
      }
    }

    int MaxElement() { return mp.rbegin()->first; }
  };

 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    WindowValues q;
    int i = 0;
    int j = 0;
    while (j < k) {
      q.Insert(nums[j]);
      ++j;
    }
    vector<int> result;
    result.push_back(q.MaxElement());
    for (; j < n; ++j) {
      q.Remove(nums[j - k]);
      q.Insert(nums[j]);
      result.push_back(q.MaxElement());
    }
    return result;
  }
};

class Solution2 {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i) {
      q.emplace(nums[i], i);
    }
    vector<int> ans = {q.top().first};
    for (int i = k; i < n; ++i) {
      q.emplace(nums[i], i);
      while (q.top().second <= i - k) {
        q.pop();
      }
      ans.push_back(q.top().first);
    }
    return ans;
  }
};

class Solution3 {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> q;
    for (int i = 0; i < k; ++i) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};
    for (int i = k; i < n; ++i) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
      while (q.front() <= i - k) {
        q.pop_front();
      }
      ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};

class Solution4 {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixMax(n), suffixMax(n);
    for (int i = 0; i < n; ++i) {
      if (i % k == 0) {
        prefixMax[i] = nums[i];
      } else {
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (i == n - 1 || (i + 1) % k == 0) {
        suffixMax[i] = nums[i];
      } else {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
      }
    }

    vector<int> ans;
    for (int i = 0; i <= n - k; ++i) {
      ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
    }
    return ans;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(), greater<>());
    return nums[k - 1];
  }
};

class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (q.size() < k) {
        q.emplace(nums[i]);
      } else {
        if (q.top() < nums[i]) {
          q.pop();
          q.emplace(nums[i]);
        }
      }
    }
    return q.top();
  }
};

class Solution {
 public:
  int quickselect(vector<int> &nums, int l, int r, int k) {
    if (l == r) {
      return nums[k];
    }
    int partition = nums[l], i = l - 1, j = r + 1;
    while (i < j) {
      do {
        i++;
      } while (nums[i] < partition);

      do {
        j--;
      } while (nums[j] > partition);

      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }
    if (k <= j)
      return quickselect(nums, l, j, k);
    else
      return quickselect(nums, j + 1, r, k);
  }

  int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();
    return quickselect(nums, 0, n - 1, n - k);
  }
};

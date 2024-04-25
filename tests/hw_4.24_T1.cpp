#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int mid;
  string path(1, 'S');
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (nums[mid] == target) {
      break;
    }
    if (low == high && nums[mid] != target) {
      break;
    }
    if (nums[mid] < target) {
      low = mid + 1;
      path.push_back('R');
    } else {
      high = mid - 1;
      path.push_back('L');
    }
  }
  path.push_back(nums[mid] == target ? 'Y' : 'N');
  cout << path << endl;
}

int main() {
  ios::sync_with_stdio(false);
  vector<int> nums;
  nums.reserve(1024);
  int temp;
  while (cin >> temp) {
    nums.push_back(temp);
  }
  int target = nums[nums.size() - 1];
  nums.pop_back();
  solve(nums, target);
  return 0;
}

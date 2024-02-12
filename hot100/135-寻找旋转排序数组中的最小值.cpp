#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMin(vector<int> &nums) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
      int mid = (low + high) / 2;
      if (nums[mid] < nums[high]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return nums[low];
  }
};

#include <bits/stdc++.h>
using namespace std;

bool numInNums(const vector<int> &nums, int num) { return std::binary_search(nums.begin(), nums.end(), num); }

// 只需找到 nums 中小于 str[0] 的最大值，低位赋 nums 中最大值即可
int easyCase(const vector<int> &nums, string str) {
  int high_bit = str[0] - '0';
  for (int i = nums.size() - 1; i >= 0; --i) {
    if (nums[i] < high_bit) {
        str[0] = nums[i] + '0';
        break;
    }
  }
  int max_value = nums[nums.size() - 1];
  for (int i = 1; i < str.length(); ++i) {
    str[i] = max_value + '0';
  }
  return stoi(str);
}

enum class ValueRange {
  LessEqualMin,
  GreaterThanMax,
  WithinMinMax
};

ValueRange getValueType(const vector<int> &nums, int bound) {
  string str = to_string(bound);
  int len = str.length();
  int min_value = stoi(string(len, nums[0] + '0'));                // 相同位数的最小值
  int max_value = stoi(string(len, nums[nums.size() - 1] + '0'));  // 相同位数的最大值
  if (bound <= min_value) {
    // bound 小于等于 nums 数组组合成的 len 位最小值，因此返回 len-1 位能够组合成的最大值
    return ValueRange::LessEqualMin;
  }
  if (bound > max_value) {
    // bound 大于 nums 数组组合成的 len 位最大值，因此返回 len 位能够组合成的最大值即可
    return ValueRange::GreaterThanMax;
  }
  return ValueRange::WithinMinMax;
}

int solve_sorted(const vector<int> &nums, int bound) {
  // 边界条件
  if (bound < 10) {
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < bound) {
        return nums[i];
      }
    }
    return 0;
  }
  string str = to_string(bound);
  int len = str.length();
  int min_value = stoi(string(len, nums[0] + '0'));                // 相同位数的最小值
  int max_value = stoi(string(len, nums[nums.size() - 1] + '0'));  // 相同位数的最大值
  if (bound <= min_value) {
    // bound 小于等于 nums 数组组合成的 len 位最小值，因此返回 len-1 位能够组合成的最大值
    return stoi(string(len - 1, nums[nums.size() - 1] + '0'));
  }
  if (bound > max_value) {
    // bound 大于 nums 数组组合成的 len 位最大值，因此返回 len 位能够组合成的最大值即可
    return max_value;
  }
  // bound 在 (min_value, max_value] 区间内，找到 nums 数组组合成的小于 bound 的最大值
  // 先考虑最高位 str[0]
  //    如果最高位不在 nums 数组范围内，则 str[0] 必然大于 nums 数组中最小值，此时：（1）只需找到 nums 中小于 str[0] 的最大值，低位赋 nums 中最大值即可
  //    如果最高位在 nums 数组范围内，即 str[0] ∈ nums，此时考虑 lower = str[1:] 情况：
  //        如果 lower 小于等于 相同位数的 nums 组合而成的最小值（string(str_len - 1, nums[0] + '0')），此时：同（1）
  //        如果 lower 大于 相同位数的 nums 组合而成的最大值，返回 str[0] + string(str_len - 1, nums[nums.size() - 1] +'0') 
  //        递归： str[0] + solve_sorted(nums, lower)
  int high_bit = str[0] - '0';
  if (!numInNums(nums, high_bit)) {
    return easyCase(nums, str);
  }
  int lower = stoi(str.substr(1));
  ValueRange valueType = getValueType(nums, lower);
  switch (valueType) {
    case ValueRange::LessEqualMin:
        return easyCase(nums, str);
        break;
    case ValueRange::GreaterThanMax:
        return stoi(string(1, str[0]) + string(len - 1, nums[nums.size() - 1] +'0'));
        break;
    case ValueRange::WithinMinMax:
        return stoi(string(1, str[0]) + to_string(solve_sorted(nums, lower)));
        break;
  }
  return -1;
}

int solve(vector<int> &nums, int bound) {
  sort(nums.begin(), nums.end());
  return solve_sorted(nums, bound);
}

void Judge(int expected, int result, const string &test_name) {
  if (expected == result) {
    std::cout << "Test: " << test_name << " Passed.\n";
  } else {
    std::cout << "Test: " << test_name << " Wrong!\t"
              << "expected: " << expected << "  result: " << result << "\n";
  }
}

#define ASSERTEQ(expected, result) (Judge(expected, result, __PRETTY_FUNCTION__))

void Test1() {
  vector<int> nums{1, 2, 9, 4};
  int n = 2533;
  int expected = 2499;
  int result = solve(nums, n);
  ASSERTEQ(expected, result);
}

void Test2() {
  vector<int> nums{1, 2, 5, 4};
  int n = 2543;
  int expected = 2542;
  int result = solve(nums, n);
  ASSERTEQ(expected, result);
}

void Test3() {
  vector<int> nums{1, 2, 5, 4};
  int n = 2541;
  int expected = 2525;
  int result = solve(nums, n);
  ASSERTEQ(expected, result);
}

void Test4() {
  vector<int> nums{1, 2, 9, 4};
  int n = 2111;
  int expected = 1999;
  int result = solve(nums, n);
  ASSERTEQ(expected, result);
}

void Test5() {
  vector<int> nums{5, 9};
  int n = 5555;
  int expected = 999;
  int result = solve(nums, n);
  ASSERTEQ(expected, result);
}

void Test6() {
  vector<int> nums{6, 7, 9};
  int n = 123;
  int expected = 99;
  int result = solve(nums, n);
  ASSERTEQ(expected, result);
}

int main() {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  return 0;
}
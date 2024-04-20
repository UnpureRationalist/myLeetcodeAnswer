#include "header.h"

// 1. 排序
class Solution {
 public:
  int findRepeatDocument(vector<int> &documents) {
    std::sort(documents.begin(), documents.end());
    int n = documents.size();
    for (int i = 1; i < n; ++i) {
      if (documents[i] == documents[i - 1]) {
        return documents[i];
      }
    }
    return -1;
  }
};

// 2. 哈希表 unordered_set
class Solution {
 public:
  int findRepeatDocument(vector<int> &documents) {
    unordered_set<int> occurances;
    for (auto &elem : documents) {
      if (occurances.find(elem) != occurances.end()) {
        return elem;
      }
      occurances.insert(elem);
    }
    return -1;
  }
};

// 3. 哈希表 由于元素范围在 [0, n-1] 使用 vector 即可模拟哈希表
class Solution {
 public:
  int findRepeatDocument(vector<int> &documents) {
    int n = documents.size();
    vector<int> occurances(n, 0);
    for (auto &elem : documents) {
      if (occurances[elem]) {
        return elem;
      }
      occurances[elem] = 1;
    }
    return -1;
  }
};

// 4. 空间复杂度 O(1) 算法，理论上排序后 a[i] = i
class Solution {
 public:
  /*
  遍历中，第一次遇到数字 x 时，将其交换至索引 x 处；
  而当第二次遇到数字 x 时，一定有 documents[x]=x，此时即可得到一组重复数字。
  */
  int findRepeatDocument(vector<int> &documents) {
    int n = documents.size();
    for (int i = 0; i < n; ++i) {
      while (documents[i] != i) {
        int num = documents[i];
        if (documents[i] == documents[num]) {
          return documents[i];
        }
        swap(documents[i], documents[num]);
      }
    }
    return -1;
  }
};

// 变例：有长度为 n+1 数组，数组中所有数字范围在 [1,n]，
// 所以数组内至少有一个重复数字。要求不改变原数组，找出数组中任意一个重复元素
class Solution {
  int countRange(const vector<int> &nums, int start, int end) {
    int count = 0;
    for (auto &num : nums) {
      if (num >= start && num <= end) {
        ++count;
      }
    }
    return count;
  }

 public:
  int findDuplicate(const vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int count = countRange(nums, start, mid);
      if (start == end) {
        if (count > 1) {
          return start;
        }
        break;
      }
      if (count > (mid - start + 1)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return -1;
  }
};

// 变例：Leetcode 442. 数组中重复的数据
class Solution {
 public:
  /*
    如果 i 恰好出现了一次，那么将 i 放在数组中下标为 i−1 的位置即可；
    如果 i 出现了两次，那么我们希望其中的一个 i 放在数组下标中为 i−1 的位置，另一个 i 放置在任意「不冲突」的位置 j。
        也就是说，数 j+1 没有在数组中出现过。

    这样一来，如果我们按照上述的规则放置每一个数，那么我们只需要对数组进行一次遍历。当遍历到位置 i 时，如果
    nums[i]−1 != i，说明 nums[i] 出现了两次（另一次出现在位置 num[i]−1），我们就可以将 num[i] 放入答案。
  */
  vector<int> findDuplicates(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (nums[i] - 1 != i) {
        ans.push_back(nums[i]);
      }
    }
    return ans;
  }
};
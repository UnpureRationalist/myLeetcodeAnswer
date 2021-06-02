#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
using namespace std;
// 方法1 排序 + 首尾双指针
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> index(nums.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(),
             [&](const int &a, const int &b) { return nums[a] < nums[b]; });
        int i = 0, j = nums.size() - 1;
        vector<int> res;
        while (i < j)
        {
            if (nums[index[i]] + nums[index[j]] == target)
            {
                res.push_back(index[i]);
                res.push_back(index[j]);
                break;
            }
            else if (nums[index[i]] + nums[index[j]] > target)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        return res;
    }
};
// 方法 2 哈希表
class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m; // 哈希表实现
        int n = nums.size();
        vector<int> res(2);
        for (int i = 0; i < n; ++i)
        {
            if (m.find(target - nums[i]) != m.end()) // 先在哈希表中查找是否存在
            {
                res[0] = i;
                res[1] = m.find(target - nums[i])->second;
                break;
            }
            m[nums[i]] = i; // 插入哈希表
        }
        return res;
    }
};
int main()
{
    vector<int> v{1, 3, 3, 8, 5, 6, 9, 8, 7, 43, 232, 32, -43};
    Solution2 s;
    vector<int> res = s.twoSum(v, 6);
    cout << res[0] << "\t" << res[1] << endl;
    return 0;
}
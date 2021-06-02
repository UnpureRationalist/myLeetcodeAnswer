#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    vector<vector<int>> res;

    void twoSum(vector<int> &nums, int target, int index)
    {
        int low = index + 1, high = nums.size() - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] == target && low != index && high != index)
            {
                res.emplace_back(vector<int>{nums[index], nums[low], nums[high]});
                int num = nums[low];
                while (low < high && nums[low] == num)
                    ++low;
                num = nums[high];
                while (low < high && nums[high] == num)
                    --high;
            }
            else if (nums[low] + nums[high] > target)
            {
                int num = nums[high];
                while (low < high && nums[high] == num)
                    --high;
            }
            else
            {
                int num = nums[low];
                while (low < high && nums[low] == num)
                    ++low;
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        auto backup = nums;
        backup.erase(unique(backup.begin(), backup.end()), backup.end());
        auto n = backup.size();
        for (int i = 0; i < n; ++i)
        {
            twoSum(nums, -backup[i], find(nums.begin(), nums.end(), backup[i]) - nums.begin());
        }
        return res;
    }
};

class Solution2
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first)
        {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second)
            {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target)
                {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target)
                {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}
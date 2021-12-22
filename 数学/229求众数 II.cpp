#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        int timesNeeded = nums.size() / 3;
        for (auto elem : nums)
        {
            mp[elem]++;
        }
        for (auto [num, times] : mp)
        {
            if (times > timesNeeded)
            {
                res.push_back(num);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for (auto &num : nums)
        {
            if (vote1 > 0 && num == element1)
            { //如果该元素为第一个元素，则计数加1
                vote1++;
            }
            else if (vote2 > 0 && num == element2)
            { //如果该元素为第二个元素，则计数加1
                vote2++;
            }
            else if (vote1 == 0)
            { // 选择第一个元素
                element1 = num;
                vote1++;
            }
            else if (vote2 == 0)
            { // 选择第二个元素
                element2 = num;
                vote2++;
            }
            else
            { //如果三个元素均不相同，则相互抵消1次
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto &num : nums)
        {
            if (vote1 > 0 && num == element1)
            {
                cnt1++;
            }
            if (vote2 > 0 && num == element2)
            {
                cnt2++;
            }
        }
        // 检测元素出现的次数是否满足要求
        if (vote1 > 0 && cnt1 > nums.size() / 3)
        {
            ans.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3)
        {
            ans.push_back(element2);
        }

        return ans;
    }
};
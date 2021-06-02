#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> subordinate;

    void calSub(vector<int> &manager)
    {
        for (int j = 0; j < manager.size(); ++j)
        {
            if (manager[j] != -1) // 若第 j 个员工的直属经理不等于 -1 ，则将 j 加入 subordinate[manager[j]]
                subordinate[manager[j]].push_back(j);
        }
    }

    int dfs(int headID, vector<int> &informTime)
    {
        if (subordinate[headID].size() == 0)
            return 0;
        int res = 0;
        for (auto i : subordinate[headID])
            res = max(res, dfs(i, informTime)); // 取全部下属通知时间的最大值 （递归深搜）
        return res + informTime[headID];
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        subordinate.resize(n);
        calSub(manager);
        return dfs(headID, informTime); // 实际上相当于从根节点开始，对树进行后序遍历
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n);

        function<bool(int)> safe = [&](int x)
        {
            if (color[x] > 0)
            {
                return color[x] == 2;
            }
            color[x] = 1;
            for (int y : graph[x])
            {
                if (!safe(y))
                {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (safe(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// 拓扑排序
class Solution2
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> inDeg(n);
        for (int x = 0; x < n; ++x)
        {
            for (int y : graph[x])
            {
                rg[y].push_back(x);
            }
            inDeg[x] = graph[x].size();
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (inDeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int y = q.front();
            q.pop();
            for (int x : rg[y])
            {
                if (--inDeg[x] == 0)
                {
                    q.push(x);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (inDeg[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}
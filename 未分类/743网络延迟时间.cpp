#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
    vector<int> cost;

    vector<vector<int>> matrix;

    void init_matrix(const vector<vector<int>> &times, int n)
    {
        matrix.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            matrix[i].resize(n + 1);
        }
        int len = times.size();
        for (int i = 0; i < len; ++i)
        {
            matrix[times[i][0]][times[i][1]] = times[i][2];
        }
    }

    struct Node
    {
        int endIndex;
        int dis;
        bool operator<(const Node &rop) const
        {
            return this->dis > rop.dis;
        }
    };

    void dijkstra(int start, int n)
    {
        cost[start] = 0;
        vector<bool> found(n + 1, false);
        found[start] = true;
        priority_queue<Node> q;
        for (int i = 1; i <= n; ++i)
        {
            if (matrix[start][i] != 0)
            {
                Node temp{i, matrix[start][i]};
                q.push(temp);
            }
        }
        while (!q.empty())
        {
            Node temp = q.top();
            cout << temp.dis << endl;
            q.pop();
            if(found[temp.endIndex])
                continue;
            cost[temp.endIndex] = temp.dis;
            found[temp.endIndex] = true;
            for (int i = 1; i <= n; ++i)
            {
                if (!found[i] && matrix[temp.endIndex][i] != 0 && cost[i] - cost[temp.endIndex] > matrix[temp.endIndex][i])
                {
                    cost[i] = matrix[temp.endIndex][i] + cost[temp.endIndex];
                    Node t{i, matrix[temp.endIndex][i] + cost[temp.endIndex]};
                    q.push(t);
                }
            }
        }
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        cost.assign(n + 1, INT_MAX);
        init_matrix(times, n);
        dijkstra(k, n);
        auto iter = find_if(cost.begin() + 1, cost.end(), [](int i)
                            { return i == INT_MAX; });
        if (iter == cost.end())
            return -1;
        else
        {
            cost[k] = INT_MAX;
            return *min_element(cost.begin() + 1, cost.end());
        }
    }
};

int main()
{

    return 0;
}
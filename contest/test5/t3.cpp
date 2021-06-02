#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int N;
int M;

vector<vector<int>> matrix;

vector<int> indegree; // 计算入度

int main()
{
    cin >> N >> M;
    matrix.resize(N, vector<int>(N, 0));

    indegree.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        int T;
        cin >> T;
        while (T--)
        {
            char c;
            cin >> c;
            int rely;
            cin >> rely;
            matrix[rely][i] = 1; // 服务 i 依赖服务 rely 。故有一条 i 到 rely 的有向边
            ++indegree[i];
        }
    }

    vector<int> order; // 记录顺序
    queue<int> q;

    for (int i = 0; i < N; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            if (i == M)
            {
                cout << "null" << endl;
                return 0;
            }
        }
    }
    // 拓扑排序
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        order.push_back(index); // 记录的拓扑排序序列可能多于实际所需的前置服务？如何判断？
        if (index == M)
            break;
        if (matrix[index][M] == 1)
        {
            --indegree[M];
            if (indegree[M] == 0)
                q.push(M);
        }
        for (int j = 0; j < N; ++j)
        {
            if (j != M)
            {
                if (matrix[index][j] == 1) // index 连通到 j
                {
                    --indegree[j];
                    if (indegree[j] == 0)
                    {
                        q.push(j);
                    }
                }
            }
        }
    }
    if (order.empty() || order.back() != M)
    {
        cout << -1 << endl;
        return 0;
    }
    int n = order.size() - 1;
    sort(order.begin(), order.end() - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << order[i];
        if (i != n - 1)
            cout << ",";
    }
    cout << endl;
    return 0;
}
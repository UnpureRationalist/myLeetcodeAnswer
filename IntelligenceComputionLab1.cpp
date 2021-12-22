#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <random>
#include <set>
#include <iomanip>
using namespace std;

enum class SearchStrategy
{
    DFS,     // 深度优先搜索
    DIJKSTRA // 有代价的广度优先搜索
};

// 边
struct Edge
{
    int endIndex;
    int weight;

    Edge() = default;

    Edge(int endIndex, int weight) : endIndex(endIndex), weight(weight) {}
};

// 顶点，用于有代价的广度优先搜索
struct Vertex
{
    int index;
    int currentWeight;

    Vertex() = default;

    Vertex(int index, int currentWeight) : index(index), currentWeight(currentWeight) {}

    bool operator<(const Vertex &rop) const
    {
        return this->currentWeight > rop.currentWeight;
    }
};

class Graph
{
    const int n;                // 节点数
    vector<list<Edge>> adjList; // 邻接表

    int ans = INT_MAX; // 路径长度 初始化为最大值

    vector<int> path;     // 路径
    vector<int> shortest; // 最短路径

    vector<bool> visited;

    void init()
    {
        ans = INT_MAX;            // 初始化为最大值
        visited.assign(n, false); // 标记所有节点未访问
        path.clear();             // 清空路径
        shortest.clear();
    }

    // 深度优先搜索
    int dfs(int start, int end)
    {
        init();

        visited[start] = true;
        path.push_back(start);

        dfsHelper(start, end, 0);

        return ans == INT_MAX ? -1 : ans;
    }

    // 深度优先搜索辅助函数
    void dfsHelper(int start, int end, int current)
    {
        if (end == start)
        {
            if (current < ans)
            {
                ans = current;
                shortest = path;
            }
            return;
        }
        for (auto edge : adjList[start])
        {
            int nextIndex = edge.endIndex;
            int nextWeight = edge.weight;
            if (!visited[nextIndex] && (current + nextWeight < ans))
            {
                visited[nextIndex] = true;
                path.push_back(nextIndex);

                dfsHelper(nextIndex, end, current + nextWeight);

                visited[nextIndex] = false;
                path.pop_back();
            }
        }
    }

    // 有代价的广度优先搜索
    int dijkstra(int start, int end)
    {
        init();
        vector<int> distance(n, INT_MAX);
        priority_queue<Vertex> q;

        vector<int> pathRecord(n, -1);

        distance[start] = 0;
        q.emplace(start, 0);

        while (!q.empty())
        {
            Vertex vert = q.top();
            q.pop();
            int index = vert.index;
            if (visited[index])
            {
                continue;
            }
            visited[index] = true;

            for (Edge edge : adjList[index])
            {
                int nextIndex = edge.endIndex;
                int nextWeight = edge.weight;
                if (!visited[nextIndex] && (distance[index] + nextWeight < distance[nextIndex]))
                {
                    pathRecord[nextIndex] = index;
                    distance[nextIndex] = distance[index] + nextWeight;
                    q.emplace(nextIndex, distance[nextIndex]);
                }
            }
        }

        ans = distance[end];
        getShortestPath(pathRecord, start, end);

        return ans == INT_MAX ? -1 : ans;
    }

    // 由 dijkstra 算法记录的 pathRecord 生成最短路径
    void getShortestPath(vector<int> &pathRecord, int start, int end)
    {
        vector<int> temp;
        int currentIndex = end;
        temp.push_back(currentIndex);
        while (pathRecord[currentIndex] != -1)
        {
            currentIndex = pathRecord[currentIndex];
            temp.push_back(currentIndex);
        }
        shortest.clear();
        shortest.assign(temp.rbegin(), temp.rend());
    }

    void show()
    {
        for (int i = 0; i < n; ++i)
        {
            cout << i << " : ";
            for (auto edge : adjList[i])
            {
                cout << "{" << edge.endIndex << ", " << edge.weight << "}\t";
            }
            cout << "\n";
        }
    }

public:
    Graph(int n, double edgeIndex = 0.5, int minWeight = 50, int maxWeight = 100) : n(n)
    {
        random_device rd;  // 将用于为随机数引擎获得种子
        mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
        uniform_int_distribution<> weightGenerator(minWeight, maxWeight);
        uniform_int_distribution<> indexGenerator(0, n - 1);

        adjList.resize(n);

        /**     利用随机数生成有向图边的权重，要保证图连通
         * 思路：
         * 1. 生成一个圈，这样能够保证任意两个节点间连通
         * 2. 随机加入一些边，保证图的随机性
         */
        // step 1: 生成圈
        for (int i = 0; i < n; ++i)
        {
            int purposeIndex = (i + 1) % n;
            int edgeWeight = weightGenerator(gen);
            adjList[i].emplace_back(purposeIndex, edgeWeight);
        }
        // step 2:随机加入边
        const int edgeNumber = n * edgeIndex;
        for (int i = 0; i < n; ++i)
        {
            set<int> exists;
            exists.insert(adjList[i].front().endIndex);
            while (exists.size() < edgeNumber)
            {
                int endIndex = indexGenerator(gen);
                // 若生成的 index 等于 i 或者 已经存在到 index 的边，重新生成随机数
                while (endIndex == i || exists.find(endIndex) != exists.end())
                {
                    endIndex = indexGenerator(gen);
                }
                exists.insert(endIndex);
                int edgeWeight = weightGenerator(gen);
                adjList[i].emplace_back(endIndex, edgeWeight);
            }
        }
    }

    // 指定起点、终点编号(合法编号范围：[0, n-1] )、搜索策略，返回最短路径值和路径
    // 返回 -1， 表示起点、终点不连通
    // 返回 -2， 表示输入不合法
    // 返回其它， 表示最短路径值
    pair<int, vector<int>> search(int start, int end, SearchStrategy strategy)
    {
        if (start < 0 || end >= n)
        {
            return {-2, vector<int>()};
        }
        int result;
        switch (strategy)
        {
        case SearchStrategy::DFS:
            result = dfs(start, end);
            break;
        case SearchStrategy::DIJKSTRA:
            result = dijkstra(start, end);
            break;
        }
        return {result, shortest};
    }
};

int main()
{
    int nodes = 50;
    Graph graph(nodes, 0.1);
    int testTimes = 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> indexGenerator(0, nodes - 1);
    while (testTimes--)
    {
        int start = indexGenerator(gen);
        int end = indexGenerator(gen);
        cout << setw(15) << start << " -> " << setw(3) << end << " : \n";
        auto resDfs = graph.search(start, end, SearchStrategy::DFS);
        auto resDijkstra = graph.search(start, end, SearchStrategy::DIJKSTRA);
        cout << "     DFS:  ans = " << setw(4) << resDfs.first << "   path = ";
        for (auto elem : resDfs.second)
        {
            cout << setw(4) << elem;
        }
        cout << endl;

        cout << "DIJKSTRA:  ans = " << setw(4) << resDijkstra.first << "   path = ";
        for (auto elem : resDijkstra.second)
        {
            cout << setw(4) << elem;
        }
        cout << "\n\n";
    }
    return 0;
}
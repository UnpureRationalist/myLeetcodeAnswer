#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/** 
 * 状态含义说明：
 *    (本岸修道士数，本岸野人数，船的位置[0：本案；1：对岸])
 * 初始状态：(3, 3, 0)
 * 目标状态：(0, 0, 1)
 * 
 * 边的表示：（修道士数，野人数， 起点[0：本岸；1：对岸])
 *  只有以下几种合法的边：
 *      (0, 1, ?)
 *      (1, 0, ?)
 *      (1, 1, ?)
 *      (2, 0, ?)
 *      (0, 2, ?)
 * 
 * 约束条件：
 *  1) 船一次最多只能载两个人；
 *  2) 在任何岸边野人数目都不得超过修道士；
 * 
 * 求解思路：
 *  1) 构造所有状态
 *  2) 连接边
 *  3) 广搜寻找图的最短路径
 */

struct Edge
{
    int monk;
    int savage;
    bool direction;

    int endIndex = -1; // 目标状态下标

    Edge() {}

    Edge(int monk, int savage, int direction) : monk(monk), savage(savage), direction(direction)
    {
    }

    Edge(int monk, int savage, int direction, int endIndex) : monk(monk), savage(savage), direction(direction), endIndex(endIndex)
    {
    }

    string toString() const
    {
        return "[" + to_string(monk) + ", " + to_string(savage) + ", " + to_string(direction) + "]";
    }
};

struct Status
{
    int monk;
    int savage;
    bool position;

    Status() {}

    Status(int monk, int savage, bool position) : monk(monk), savage(savage), position(position)
    {
    }

    bool isStart() const
    {
        return monk == 3 && savage == 3 && !position;
    }

    bool isEnd() const
    {
        return monk == 0 && savage == 0 && position;
    }

    bool isLegal() const
    {
        if (!(monk >= 0 && monk <= 3 && savage >= 0 && savage <= 3))
        {
            return false;
        }
        if (monk != 0 && monk < savage)
        {
            return false;
        }
        if (monk != 3 && (3 - monk < 3 - savage))
        {
            return false;
        }
        return true;
    }

    bool operator==(const Status &rop) const
    {
        return this->monk == rop.monk && this->savage == rop.savage && this->position == rop.position;
    }

    Status getNextStatus(Edge edge)
    {
        if (this->position != edge.direction)
        {
            throw "Error when get next status!";
        }
        if (!(this->position))
        { // 船在本案
            return Status{this->monk - edge.monk, this->savage - edge.savage, !(this->position)};
        }
        else
        { // 船在对岸
            return Status{this->monk + edge.monk, this->savage + edge.savage, !(this->position)};
        }
    }

    string toString() const
    {
        return "(" + to_string(monk) + ", " + to_string(savage) + ", " + to_string(position) + ")";
    }
};

vector<Status> statuses;

void generateAllStatus()
{
    statuses.emplace_back(3, 3, false); // 初始状态
    statuses.emplace_back(0, 0, true);  // 目标状态
    for (int monk = 0; monk <= 3; ++monk)
    {
        for (int savage = 0; savage <= 3; ++savage)
        {
            Status s1{monk, savage, true};
            Status s2{monk, savage, false};
            if (!s1.isStart() && !s1.isEnd() && s1.isLegal())
            {
                statuses.push_back(s1);
            }
            if (!s2.isStart() && !s2.isEnd() && s2.isLegal())
            {
                statuses.push_back(s2);
            }
        }
    }
}

int n;

vector<vector<Edge>> edges;

void buildEdge()
{
    n = statuses.size();
    edges.resize(n);
    for (int i = 0; i < n; ++i)
    {
        Status status = statuses[i];
        vector<Edge> tempEdges;
        tempEdges.emplace_back(0, 1, status.position);
        tempEdges.emplace_back(1, 0, status.position);
        tempEdges.emplace_back(1, 1, status.position);
        tempEdges.emplace_back(2, 0, status.position);
        tempEdges.emplace_back(0, 2, status.position);
        for (auto edge : tempEdges)
        {
            Status nextStatus = status.getNextStatus(edge);
            if (nextStatus.isLegal())
            {
                auto iter = find(statuses.begin(), statuses.end(), nextStatus);
                if (iter != statuses.end())
                {
                    int endIndex = iter - statuses.begin();
                    edges[i].emplace_back(edge.monk, edge.savage, edge.direction, endIndex);
                }
            }
        }
    }
}

vector<Edge> shortest;
vector<Edge> path;

const int endIndex = 1;

vector<bool> visited;

const Status startStatus{3, 3, 0}, endStatus{0, 0, 1};

void printPath(vector<Edge> edges)
{
    Status next = startStatus;
    for (auto edge : edges)
    {
        next = next.getNextStatus(edge);
        cout << " -- edge=" << edge.toString() << "--> " << next.toString();
    }
    cout << endl;
}

void findPath(int start)
{
    if (start == endIndex)
    {
        cout << startStatus.toString();
        printPath(path);
        if (path.size() <= shortest.size())
        {
            shortest = path;
        }
        return;
    }
    for (auto edge : edges[start])
    {
        int nextIndex = edge.endIndex;
        if (!visited[nextIndex])
        {
            visited[nextIndex] = true;
            path.push_back(edge);

            findPath(nextIndex);

            visited[nextIndex] = false;
            path.pop_back();
        }
    }
}

int main()
{
    generateAllStatus();
    buildEdge();

    visited.resize(n, false);
    visited[0] = true;
    shortest.resize(n);

    findPath(0);

    cout << "shortest legth = " << shortest.size() << " . shortest path : \n";
    cout << startStatus.toString();
    printPath(shortest);
    return 0;
}
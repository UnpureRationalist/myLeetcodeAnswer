/** 
 *              《智能计算技术》实验 3
 * 问题描述：
 * 
 * 生成一个 NxN 的二维网格, 随机指定一些格子为障碍, 左下角有辆车（占一个格子）要去
 * 右上角, 使用 A* 算法先计算起点到终点的不撞到障碍的最短路径. 计算完后, 利用路
 * 径上每个点的局部曲率, 以及到周围最近障碍的距离来控制车辆的速度. 要求使用模糊逻辑
 * 建立 曲率小, 离障碍距离远, 车速快三个模糊集合, 构建曲率小——车速快的关系矩阵, 
 * 距离远——车速快的关系矩阵, 根据 A* 路径上每个点实际的曲率和离障碍物的距离, 使用
 * 模糊推理及过规则合成,得到目标的瞬时速度, 车辆按瞬时速度从左下到右上沿着 A* 路径行驶. 
 * 
 * 关键求解步骤：
 * 1. 生成随机障碍
 * 2. 利用 A* 算法规划出起点到终点路径
 *      2.1 启发函数的选取：8-向移动，不能选取曼哈顿距离，本次实验选取欧氏距离
 *      2.2 采用 A* 搜索求解路径
 * 3. 计算路径上每个点的 局部曲率 以及 到最近障碍物的距离
 *      3.1 二维离散曲线的计算：三角形外接圆曲率法
 *      3.2 距离最近的障碍物距离：遍历地图寻找最小值
 * 4. 建立曲率小, 离障碍距离远, 车速快 3 个模糊集合，并计算两个关系矩阵
 * 5. 根据曲率、距离、关系矩阵，计算速度
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <random>
#include <set>
#include <unordered_map>
using namespace std;

int n = 20;               // 地图边长
vector<vector<bool>> map; // 地图 1: 道路  0: 障碍
vector<vector<int>> realCost;
vector<vector<bool>> visited;

struct Point
{
    int row, col;
    Point() = default;

    Point(int row, int col) : row(row), col(col) {}

    void setValue(int row, int col)
    {
        this->row = row;
        this->col = col;
    }

    bool operator==(const Point &rop) const
    {
        return this->row == rop.row && this->col == rop.col;
    }

    bool operator!=(const Point &rop) const
    {
        return !(*this == rop);
    }

    double distance(const Point &rop) const
    {
        int diffX = rop.row - this->row;
        int diffY = rop.col - this->col;
        return sqrt(diffX * diffX + diffY * diffY);
    }
};

Point start{n - 1, 0};  // 起点
Point target{0, n - 1}; // 目标点

// 表示小车走的方向（操作）
enum class Direction : uint8_t
{
    Up,
    Down,
    Left,
    Right,
    UpLeft,
    UpRight,
    DownLeft,
    DownRight,
    None
};

// 8 个方向移动时对应坐标变化
vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
vector<string> dirString{"Up", "Down", "Left", "Right", 
                            "UpLeft", "UpRight", "DownLeft", "DownRight", "none"};
// 搜索时的状态
struct Status
{
    Point point;
    double score; // 节点的估价函数值

    Status() = default;

    Status(int row, int col, double score) : point(row, col), score(score) {}

    Status(Point point, double score) : point(point), score(score) {}

    bool operator<(const Status &rop) const
    {
        return this->score > rop.score;
    }

    int row() const
    {
        return point.row;
    }

    int col() const
    {
        return point.col;
    }
};

// 将整数转换为坐标
Point trans(int x)
{
    int row = x / n;
    int col = x % n;
    return {row, col};
}

// 判断生成的坐标是否合法且不重复
bool isLegalRandomPos(const Point &point)
{
    // 若等于起点或终点 返回 false
    if (point == start || point == target)
    {
        return false;
    }
    // 返回是否为障碍物
    return map[point.row][point.col];
}

// 随机生成障碍
void generateObstacles()
{
    random_device rd;
    mt19937 gen(rd());
    // 随机生成 [0, n * n - 1] 区间内的整数
    uniform_int_distribution<> indexGenerator(0, n * n - 1);

    int obstacleNumber = (n * n - 2) * 0.25;
    while (obstacleNumber--)
    {
        int x = indexGenerator(gen);
        Point point = trans(x);
        while (!isLegalRandomPos(point))
        {
            point = trans(indexGenerator(gen));
        }
        map[point.row][point.col] = false;
    }
}

string splitLine(4 * n + 1, '-');

// 初始化相关数据结构
void init()
{
    // 设置地图 size 并初始化
    map.assign(n, vector<bool>(n, true));

    // 设置起点与终点
    start.setValue(n - 1, 0);
    target.setValue(0, n - 1);

    // 随机生成障碍
    generateObstacles();

    // 设置分割线
    splitLine.assign(4 * n + 1, '-');

    // 设置实际代价矩阵
    realCost.assign(n, vector<int>(n, 0));
    realCost[start.row][start.col] = 0;

    // 初始化 是否已经访问 标记数组
    visited.assign(n, vector<bool>(n, false));
}

// 起点到目前节点实际代价
double g(const Point &current)
{
    return realCost[current.row][current.col];
}

// 启发函数
double h(const Point &current)
{
    int diffx = current.row - target.row;
    int diffy = current.col - target.col;
    return sqrt(diffx * diffx + diffy * diffy);
}

// 估价函数
double f(const Point &current)
{
    return h(current) + g(current);
}

// 判断扩展节点是否合法
bool isLegalGeneratedPos(const Point &point)
{
    int x = point.row;
    int y = point.col;
    // 位置不在地图内 返回 false
    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        return false;
    }
    // 障碍物 返回 false
    if (!map[x][y])
    {
        return false;
    }
    return !visited[x][y];
}

// 生成最短路径
vector<Point> generatePath(const vector<vector<Point>> &pathRecord)
{
    vector<Point> res;
    res.push_back(target);
    int x = target.row;
    int y = target.col;
    Point end{-1, -1};
    while (pathRecord[x][y] != end)
    {
        int preX = pathRecord[x][y].row;
        int preY = pathRecord[x][y].col;
        x = preX;
        y = preY;
        res.emplace_back(x, y);
    }
    reverse(res.begin(), res.end());
    return res;
}

// A* 搜索寻找最短路径
pair<int, vector<Point>> AStarSearch()
{
    int steps = -1;
    vector<vector<Point>> pathRecord(n, vector<Point>(n, {-1, -1}));
    Status s0(start, f(start));
    priority_queue<Status> q;
    q.push(s0);
    while (!q.empty())
    {
        Status current = q.top();
        q.pop();

        // 找到目标节点 退出循环
        if (current.point == target)
        {
            steps = realCost[target.row][target.col];
            break;
        }

        // 节点已访问 continue
        if (visited[current.row()][current.col()])
        {
            continue;
        }
        visited[current.row()][current.col()] = true;

        // 扩展节点
        for (int i = 0; i < 8; ++i)
        {
            int nextRow = current.row() + dirs[i][0];
            int nextCol = current.col() + dirs[i][1];
            Point next{nextRow, nextCol};
            if (isLegalGeneratedPos(next))
            {
                // 记录 realCost 和 路径
                realCost[nextRow][nextCol] = realCost[current.row()][current.col()] + 1;
                pathRecord[nextRow][nextCol] = {current.row(), current.col()};
                q.emplace(next, f(next)); // 入队
            }
        }
    }
    vector<Point> path;
    if (steps != -1)
    {
        path = generatePath(pathRecord);
    }
    return {steps, path};
}

// 表示小车规划出的路径节点
struct PathNode
{
    Point point;
    double curv;                         // 曲率
    double dis;                          // 距离最近障碍点距离
    Direction nextDir = Direction::None; // 下一步方向
    double speed = 0;                    // 速度

    PathNode() = default;

    PathNode(int row, int col) : point(row, col) {}

    PathNode(Point point, double curv, double dis, Direction nextDir) :
         point(point), curv(curv), dis(dis), nextDir(nextDir) {}

    string toString() const
    {
        return "pos[" + to_string(point.row) + "," + to_string(point.col) + "]"
                 + " curv = " + to_string(curv) + " dis = " + to_string(dis)
                 + " speed = " + to_string(speed)
                 + " dir = " + dirString[static_cast<uint8_t>(nextDir)];
    }

    void show() const
    {
        cout << toString() << endl;
    }
    
    void setSpeed(double speed)
    {
        this->speed = speed;
    }

    bool operator== (const PathNode& rop) const
    {
        return this->point == rop.point;
    }
};

// 计算某点到距离最近障碍物点距离
double calDistance(const Point &current)
{
    double ans = 2 * n; // 地图边长为 n，初始化为 2n
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!map[i][j])
            {
                double dis = current.distance({i, j});
                ans = min(ans, dis);
            }
        }
    }
    return ans;
}

// 判断是否三点共线
bool isLinear(const Point &pre, const Point &current, const Point &next)
{
    double diffX1 = current.row - pre.row;
    double diffY1 = current.col - pre.col;
    double diffX2 = next.row - current.row;
    double diffY2 = next.col - current.col;
    if (diffX1 == 0 && diffX2 == 0)
    {
        return true;
    }
    if (diffX1 != 0 && diffX2 != 0)
    {
        double k1 = diffY1 / diffX1;
        double k2 = diffY2 / diffX2;
        return k1 == k2;
    }
    return false;
}

// 计算某点曲率
double calCurvature(const Point &pre, const Point &current, const Point &next)
{
    if (isLinear(pre, current, next))
    {
        return 0.0;
    }
    // 根据 3 个点坐标做外接圆，进而求出曲率
    // 3 个点分别记作 A B C 点，形成三角形，其对边记作 a b c
    // 根据正弦定理： a/sinA = b/sinB = c/sinC = 2R
    // 根据余弦定理：cos(A) = ...
    double a = current.distance(next);
    double b = pre.distance(next);
    double c = current.distance(pre);
    double cosAlpha = (b * b + c * c - a * a) / (2 * b * c);
    double alpha = acos(cosAlpha);
    double sinAlpha = sin(alpha);
    double r = a / sinAlpha / 2;
    return 1.0 / r;
}

// 计算当前到到下一点需要走的方向
Direction calDirection(const Point &current, const Point &next)
{
    int diffX = next.row - current.row;
    int diffY = next.col - current.col;
    vector<int> temp{diffX, diffY};
    uint8_t index = find(dirs.begin(), dirs.end(), temp) - dirs.begin();
    return static_cast<Direction>(index);
}

// 计算曲率和距离障碍物最短距离
vector<PathNode> calCurvAndDis(const vector<Point> &path)
{
    int size = path.size();
    vector<PathNode> res(size);

    for (int i = 0; i < size; ++i)
    {
        double dis = calDistance(path[i]);
        double curv = 0;
        Direction direction = Direction::None;
        if (i == 0) // 起点
        {
            curv = calCurvature({n, -1}, path[i], path[i + 1]);
            direction = calDirection(path[i], path[i + 1]);
        }
        else if (i == size - 1) // 终点
        {
            curv = calCurvature(path[i - 1], path[i], {-1, n});
        }
        else
        {
            curv = calCurvature(path[i - 1], path[i], path[i + 1]);
            direction = calDirection(path[i], path[i + 1]);
        }
        res[i].point = path[i];
        res[i].curv = curv;
        res[i].dis = dis;
        res[i].nextDir = direction;
    }

    return res;
}

const double defaultValue = 0.5;
const double minSetValue = 0.01;
vector<double> curvVagSet;  // 曲率小 模糊集合
vector<double> disVagSet;   // 距离大 模糊集合
vector<double> speedVagSet; // 车速快 模糊集合

set<double> curvSet;    // 值集合
set<double> disSet;
vector<int> speedSet{5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 
                    55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

// 生成 曲率小, 离障碍距离远, 车速快 3 个模糊集合
// 1. 对于 曲率小 隶属函数均按以下准则计算：
// 设原集合最大值为 Max ，最小值为 Min ，
// 则 trans(elem) = (Max - elem) / (Max - Min)
//
// 2. 对于 离障碍距离远, 车速快 隶属函数均按以下准则计算：
// 设原集合最大值为 Max ，最小值为 Min ，
// 则 trans(elem) = (elem - Min) / (Max - Min)
void generateVagueSet(const vector<PathNode> &pathNodes)
{
    for (auto &elem : pathNodes)
    {
        curvSet.insert(elem.curv);
        disSet.insert(elem.dis);
    }

    // 曲率小的模糊集合
    double minCurv = *curvSet.begin(), maxCurv = *curvSet.rbegin();
    double width = maxCurv - minCurv;
    for (auto elem : curvSet)
    {
        double val = width == 0 ? defaultValue : ((maxCurv - elem) / width);
        val = val == 0 ? minSetValue : val;
        curvVagSet.push_back(val);
    }

    // 距离障碍物距离远的模糊集合
    double minDis = *disSet.begin(), maxDis = *disSet.rbegin();
    width = maxDis - minDis;
    for (auto elem : disSet)
    {
        double val = width == 0 ? defaultValue : ((elem - minDis) / width);
        val = val == 0 ? minSetValue : val;
        disVagSet.push_back(val);
    }

    // 车速快的模糊集合
    double maxSpeed = *max_element(speedSet.begin(), speedSet.end());
    double minSpeed = *min_element(speedSet.begin(), speedSet.end());
    width = maxSpeed - minSpeed;
    for (auto elem : speedSet)
    {
        double val = width == 0 ? defaultValue : (elem - minSpeed) / width;
        val = val == 0 ? minSetValue : width == 0 ? defaultValue : (elem - minSpeed) / width;
        speedVagSet.push_back(val);
    }
}

// 两个关系矩阵
vector<vector<double>> curv2speed;
vector<vector<double>> dis2speed;

// 构建关系矩阵
void buildRelationMatrix(vector<vector<double>> &matrix,
                         const vector<double> &lop,
                         const vector<double> &rop)
{
    int row = lop.size();
    int col = rop.size();
    matrix.resize(row, vector<double>(col));
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            matrix[i][j] = min(lop[i], rop[j]);
        }
    }
}

// 计算速度向量
vector<double> calSpeedVector(const vector<double>& lop, const vector<vector<double>>& matrix)
{
    int rowSize = matrix.size();
    int colSize = matrix.begin()->size();
    vector<double> res(colSize);
    for (int col = 0; col < colSize; ++col)
    {
        vector<double> temp;
        for (int row = 0; row < rowSize; ++row)
        {
            temp.push_back(min(lop[row], matrix[row][col]));
        }
        res[col] = *max_element(temp.begin(), temp.end());
    }
    return res;
}

void showVector(const vector<double>& v)
{
    for (auto elem : v)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

// 根据曲率、距离、两个关系矩阵计算速度
void setPathNodeSpeed(vector<PathNode>& pathNodes)
{
    double minCurv = *curvSet.begin(), maxCurv = *curvSet.rbegin();
    double curvWidth = maxCurv - minCurv;

    double minDis = *disSet.begin(), maxDis = *disSet.rbegin();
    double disWidth = maxDis - minDis;

    const int curvSize = curvSet.size();
    const int disSize = disSet.size();

    unordered_map<double, int> curvMap;
    unordered_map<double, int> disMap;
    int index = 0;
    for (auto elem : curvSet)
    {
        curvMap[elem] = index++;
    }
    index = 0;
    for (auto elem : disSet)
    {
        disMap[elem] = index++;
    }

    for (auto& node : pathNodes)
    {
        vector<double> curvVector(curvSize, 0.0);
        vector<double> disVector(disSize, 0.0);
        double curv = node.curv;
        double dis = node.dis;
        curv = (curvWidth == 0 ? defaultValue : (maxCurv - curv) / curvWidth);
        curv = curv == 0 ? minSetValue : curv;
        dis = (disWidth == 0 ? defaultValue : (dis - minDis)/ disWidth);
        dis = dis == 0 ? minSetValue : dis;
        curvVector[curvMap[curv]] = curv;
        disVector[disMap[dis]] = dis;

        vector<double> speed1 = calSpeedVector(curvVector, curv2speed);
        vector<double> speed2 = calSpeedVector(disVagSet, dis2speed);
        
        vector<double> unionRes(speed1.size());
        for (int i = 0; i < speed1.size(); ++i)
        {
            unionRes[i] = max(speed1[i], speed2[i]);    // 模糊集合并
        }
        // 加权计算速度
        double up = 0.0, down = 0.0;
        for (int i = 0; i < unionRes.size(); ++i)
        {
            // up += unionRes[i] * speedSet[i];
            // down += unionRes[i];
            up += speed1[i] * speedSet[i];
            up += speed2[i] * speedSet[i];
            down += speed1[i];
            down += speed2[i];
        }
        
        node.setSpeed(up / down);
    }
}

// 打印地图
void printMap(const vector<PathNode>& pathNodes)
{
    int i = 0;
    for (const auto &line : map)
    {
        cout << splitLine << endl
             << '|';
        int j = 0;
        for (const auto &elem : line)
        {
            bool isPath = find(pathNodes.begin(), pathNodes.end(), PathNode{i, j}) != pathNodes.end();
            if (isPath)
            {
                cout << ' ' << '*' << " |";
            }
            else 
            {
                cout << ' ' << (elem ? ' ' : 'x') << " |";
            }
            ++j;
        }
        cout << endl;
        ++i;
    }
    cout << splitLine << endl;
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        n = atoi(argv[1]);
        n = n < 5 ? 20 : n; // 若输入边长小于 5，设置为 20
    }

    // 数据结构初始化
    init();

    // A* 搜索
    auto [steps, path] = AStarSearch();

    // 计算曲率和距离障碍物最小距离
    vector<PathNode> pathNodes = calCurvAndDis(path);

    // 生成 3 个模糊集合
    generateVagueSet(pathNodes);

    // 计算两个关系矩阵
    buildRelationMatrix(curv2speed, curvVagSet, speedVagSet);
    buildRelationMatrix(dis2speed, disVagSet, speedVagSet);

    // 计算瞬时速度
    setPathNodeSpeed(pathNodes);

    // 打印
    printMap(pathNodes);
    cout << steps << endl;
    for (auto elem : pathNodes)
    {
        elem.show();
    }
    return 0;
}
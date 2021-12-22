/** 
 * 《智能计算技术》实验二
 * 搜索树
 * 5x5格子的一字棋问题，参照PPT上的例子来实现。（PPT上是3x3）。 
 * 要求：
 *      加入a-β剪枝策略
 *      Max方和Min方都用博弈树来决策
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

enum class MapStatus
{
    MAX, // A 方，先走，X 表示
    MIN, // B 方，后走，O 表示
    INIT // 初始化
};

ostream &operator<<(ostream &out, MapStatus status)
{
    switch (status)
    {
    case MapStatus::INIT:
        out << "INIT";
        break;
    case MapStatus::MAX:
        out << "MAX";
        break;
    case MapStatus::MIN:
        out << "MIN";
        break;
    }
    return out;
}

const int n = 5;
vector<vector<MapStatus>> map(n, vector<MapStatus>(n, MapStatus::INIT));
string s("XO ");
string splitLine(4 * n + 1, '-');

// 打印当前状态
void printCurrentStatus(ostream &out = cout)
{
    for (auto line : map)
    {
        out << splitLine << endl
            << '|';
        for (auto status : line)
        {
            out << ' ' << s[static_cast<int>(status)] << " |";
        }
        out << endl;
    }
    out << splitLine << endl
        << endl;
}

// 估价函数（对一方）
int evaluate(MapStatus status)
{
    int ans = 0;

    // 行
    for (int row = 0; row < n; ++row)
    {
        int col = 0;
        for (; col < n; ++col)
        {
            if (map[row][col] != MapStatus::INIT && map[row][col] != status)
            {
                break;
            }
        }
        ans += col == n;
    }
    // 列
    for (int col = 0; col < n; ++col)
    {
        int row = 0;
        for (; row < n; ++row)
        {
            if (map[row][col] != MapStatus::INIT && map[row][col] != status)
            {
                break;
            }
        }
        ans += row == n;
    }
    // 对角线
    // i = j
    int i = 0;
    for (; i < n; ++i)
    {
        if (map[i][i] != MapStatus::INIT && map[i][i] != status)
        {
            break;
        }
    }
    ans += i == n;
    // j = n - i - 1
    for (i = 0; i < n; ++i)
    {
        if (map[i][n - i - 1] != MapStatus::INIT && map[i][n - i - 1] != status)
        {
            break;
        }
    }
    ans += i == n;
    // cerr << "status = " << status << " score = " << ans << endl;
    return ans;
}

// 估价函数（对当前状态）
int evaluate()
{
    int ans = evaluate(MapStatus::MAX) - evaluate(MapStatus::MIN);
    // printCurrentStatus(cerr);
    // cerr << "score = " << ans << endl;
    return ans;
}

// 是否结束
bool over()
{
    int sum = 0;
    for (auto line : map)
    {
        for (auto status : line)
        {
            sum += status == MapStatus::INIT;
        }
    }
    return sum <= 1;
}

// 基于当前状态，生成所有（或关系）子节点
vector<pair<int, int>> generateOr()
{
    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j] == MapStatus::INIT)
            {
                res.emplace_back(i, j);
            }
        }
    }
    return res;
}

// 根据一个或关系子节点，生成所有可能的与关系子节点
vector<pair<int, int>> generateAnd(const pair<int, int> &orStatus)
{
    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((!(i == orStatus.first && j == orStatus.second)) && map[i][j] == MapStatus::INIT)
            {
                res.emplace_back(i, j);
            }
        }
    }
    return res;
}

// 搜索
void search()
{
    vector<pair<int, int>> ors = generateOr();
    vector<int> orScores;
    vector<vector<int>> matrix;
    vector<pair<int, int>> possiblePos;
    for (const auto [row, col] : ors)
    {
        map[row][col] = MapStatus::MAX;

        vector<pair<int, int>> ands = generateAnd({row, col});
        vector<int> andScores;
        int maxValue = INT_MIN;
        for (const auto [andRow, andCol] : ands)
        {
            map[andRow][andCol] = MapStatus::MIN;

            andScores.push_back(evaluate());

            map[andRow][andCol] = MapStatus::INIT;
        }
        matrix.push_back(andScores);
        // 求父节点（与节点）的启发函数值
        int minIndex = min_element(andScores.begin(), andScores.end()) - andScores.begin();
        int minValue = andScores[minIndex];
        possiblePos.push_back(ands[minIndex]);
        // alpha 剪枝
        if (minValue > maxValue)
        {
            orScores.push_back(minValue);
            maxValue = minValue;
        }

        map[row][col] = MapStatus::INIT;
    }
    // 由或关系节点倒推父节点启发函数值
    int maxIndex = max_element(orScores.begin(), orScores.end()) - orScores.begin();
    // MAX 方选择或节点中最大值扩展，形成新棋局
    map[ors[maxIndex].first][ors[maxIndex].second] = MapStatus::MAX;
    auto &andStatus = matrix[maxIndex];
    int minIndex = min_element(andStatus.begin(), andStatus.end()) - andStatus.begin();
    vector<pair<int, int>> ands = generateAnd(ors[maxIndex]);
    // MIN 方选择节点中最小值扩展
    map[possiblePos[maxIndex].first][possiblePos[maxIndex].second] = MapStatus::MIN;
    // map[ands[minIndex].first][ands[minIndex].second] = MapStatus::MIN;
}

int main()
{
    while (!over())
    {
        search();
        printCurrentStatus();
    }
    return 0;
}
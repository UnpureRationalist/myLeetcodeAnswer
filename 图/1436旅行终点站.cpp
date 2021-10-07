#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /** 
     * 求旅行终点城市
     * 看做一个有向图，即求 出度 为 0 的节点
     */
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> outDegree;
        for (auto citys : paths)
        {
            if (outDegree.find(citys[1]) == outDegree.end())
            {
                outDegree[citys[1]] = 0;
            }
            outDegree[citys[0]]++;
        }
        string res;
        for (auto elem : outDegree)
        {
            if (elem.second == 0)
            {
                res = elem.first;
                break;
            }
        }
        return res;
    }
};
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matchPairList int整型vector<vector<>> 人和工作的匹配对，数组每一个元素包含两个id，第一个是人的id，第二个是工作的id,id不会重复，仅做编号使用，没有实际意义
     * @return int整型
     */
    int maxMatch(vector<vector<int>> &matchPairList)
    {
        // write code here
        set<int> persons, jobs;
        map<int, set<int>> mp; // job_id 到 意向该工作的所有 person_id
        map<int, int> jobCount;
        map<int, int> personCount;
        for (auto &v : matchPairList)
        {
            ++jobCount[v[1]];
            ++personCount[v[0]];
            persons.insert(v[0]);
            jobs.insert(v[1]);
            if (mp.find(v[1]) == mp.end())
            {
                mp.insert({v[1], set<int>{v[0]}});
            }
            else
            {
                mp.find(v[1])->second.insert(v[0]);
            }
        }
        int res = 0;
        vector<int> allJobs(jobs.begin(), jobs.end());
        sort(allJobs.begin(), allJobs.end(), [&jobCount](auto lop, auto rop) {
            return jobCount[lop] < jobCount[rop]; // 优先选择人少的工作
        });
        for (auto &job_id : allJobs)
        {
            auto &selectPersons = mp[job_id];
            vector<int> person_ids(selectPersons.begin(), selectPersons.end());
            sort(person_ids.begin(), person_ids.end(), [&personCount](auto lop, auto rop) {
                return personCount[lop] < personCount[rop]; // 优先分配给选工作数少的人
            });
            for (auto &person_id : person_ids)
            {
                if (persons.find(person_id) != persons.end())
                {
                    ++res;
                    persons.erase(person_id);
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}
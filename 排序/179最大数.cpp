#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        for( ; i < n; ++i)
            if(nums[i] != 0)
                break;
        if (i == n)
            return string("0");
        vector<string> vs(n);
        for (int i = 0; i < n; ++i)
            vs[i] = to_string(nums[i]);
        sort(vs.begin(), vs.end(),
             [](const string &lop, const string &rop) -> bool {
                 if (lop + rop < rop + lop)
                     return false;
                 return true;
             });
        string res;
        for (auto &s : vs)
            res += s;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 0, 1};
    cout << s.largestNumber(v) << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    struct comp
    {
        bool operator()(string &s1, string &s2) const
        {
            if (s1.length() == s2.length())
                return s1 < s2;
            else
            {
                if( (s1 + s2) < (s2 + s1) )
                    return true;
                else
                    return false;
            }
        }
    };

public:
    string minNumber(vector<int> &nums)
    {
        vector<string> vs;
        for (auto elem : nums)
            vs.push_back(to_string(elem));
        sort(vs.begin(), vs.end(), comp());
        string res;
        for(auto &s : vs)
            res += s;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v{12, 121};
    cout << s.minNumber(v) << endl;
    return 0;
}
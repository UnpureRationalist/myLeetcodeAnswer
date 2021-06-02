#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        sort(s.begin(), s.end());
        vector<string> res;
        res.push_back(s);
        while (next_permutation(s.begin(), s.end()))
        {
            res.push_back(s);
        }
        return res;
    }
};

int main()
{

    return 0;
}
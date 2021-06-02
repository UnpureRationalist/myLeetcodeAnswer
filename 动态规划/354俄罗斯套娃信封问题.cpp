#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    struct env
    {
        int width;
        int height;
        bool operator<(const env &r) const
        {
            if (this->width != r.width)
                return this->width < r.width;
            else
                return this->height > r.height;
        }

        env(int w, int h) : width(w), height(h) {}
        env() {}
    };

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        vector<env> v;
        for (int i = 0; i < n; ++i)
            v.emplace_back(envelopes[i][0], envelopes[i][1]);
        sort(v.begin(), v.end());
        vector<int> res(n);
        fill(res.begin(), res.end(), 1);
        for(int i = 0;i < n; ++i)
        {
            for(int j = 0;j < i; ++j)
            {
                if(v[i].height > v[j].height)
                {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }
        return *max_element(res.begin(), res.end());
    }
};

int main()
{

    return 0;
}
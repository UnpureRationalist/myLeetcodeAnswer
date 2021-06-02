#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
struct Thing
{
    int v, price;

    bool operator<(const Thing &r) const
    {
        if(v != r.v)
        {
            return price > r.price;
        }
        else
        {
            return v < r.v;
        }
    }
};

int main()
{
    cin >> N >> M;
    vector<Thing> vec;
    set<int> bag;
    vec.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i].v >> vec[i].price;
    }
    int r;
    for (int i = 0; i < M; ++i)
    {
        cin >> r;
        bag.insert(r);
    }

    sort(vec.begin(), vec.end());
    unsigned long long res = 0;
    int i = 0;
    while (!bag.empty())
    {
        int v = vec[i].v;
        auto iter = bag.find(v);
        if (iter != bag.end())
        {
            res += vec[i].price;
            bag.erase(iter);
        }
        else
        {
            iter = bag.upper_bound(v);
            if (iter != bag.end())
            {
                res += vec[i].price;
                bag.erase(iter);
            }
        }
        ++i;
    }
    cout << res << endl;
    return 0;
}
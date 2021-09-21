#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;
int n;

vector<int> getNext(int pos)
{
    if (pos >= 1 && pos <= n - 1)
        return {pos - 1, pos + 1};
    if (pos == 0)
        return {1, n - 1};
    if (pos == n - 1)
        return {n - 2, 0};
    return {};
}

bool biggerThanNeighbor(int pos, const vector<int> &papers)
{
    vector<int> next = getNext(pos);
    if (v[pos] > v[next[0]] && v[pos] > v[next[1]])
    {
        return papers[pos] <= v[next[0]] || papers[pos] <= v[next[1]];
    }
    if ((v[pos] > v[next[0]] && papers[pos] <= v[next[0]]) ||
        (v[pos] > v[next[1]] && papers[pos] <= v[next[1]]))
        return true;
    return false;
}

void work(vector<int> &papers)
{
    bool goon = true;
    while (goon)
    {
        goon = false;
        for (int i = 0; i < n; ++i)
        {
            bool bigger = biggerThanNeighbor(i, papers);
            goon |= bigger;
            if (bigger)
                ++papers[i];
        }
    }
}

int main()
{
    int temp;
    while (cin >> temp)
    {
        v.push_back(temp);
    }

    n = v.size();
    vector<int> papers(n, 1);
    work(papers);
    cout << accumulate(papers.begin(), papers.end(), 0) << endl;
    return 0;
}
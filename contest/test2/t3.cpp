#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int q;


int main()
{
    vector<vector<int>> input;
    cin >> n;
    input.resize(n);
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        input[i].resize(num);
        for(int j = 0; j < num; ++j)
        {
            cin >> input[i][j];
        }
    }

    cin >> q;
    while(q--)
    {
        int p;
        cin >> p;
        vector<int> select;
        select.resize(p);
        for(int i = 0; i < p; ++i)
        {
            cin >> select[i];
        }
        int k;  // 第 k 小
        cin >> k;
        vector<int> merge;
        for(int i = 0; i < p; ++i)
        {
            int index = select[i] - 1;
            for(auto elem : input[index])
                merge.push_back(elem);
        }
        sort(merge.begin(), merge.end());
        cout << merge[k - 1] << endl;
    }
    return 0;
}
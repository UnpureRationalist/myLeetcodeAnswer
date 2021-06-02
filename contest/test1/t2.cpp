#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int n;
long long solve(vector<long long> v)
{
    if(v.size() == 3)
        return *max_element(v.begin(), v.end());
    long long res = 0;
    for(int i = 0;i < v.size(); ++i)
    {
        vector<long long> temp = v;
        temp.erase(temp.begin()+i);
        if(i == v.size()-1)
            temp.erase(temp.begin());
        else
            temp.erase(temp.begin()+i+1);
        if(i == 0)
            temp.erase(temp.end()-1);
        else    
            temp.erase(temp.begin()+i-1);
        res = max(res, v[i]+solve(temp));
    }
    return res;
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        vector<long long> val(n);
        for(int i = 0;i < n; ++i)
            cin >> val[i];
        cout << solve(val) << endl;
        /*
             n == 3 select MAX
             n > 3  max(  val[i]+solve(left) )     f(n) = n*f(n-3)  O(n!)   xxx
        */
    }
    return 0;
}
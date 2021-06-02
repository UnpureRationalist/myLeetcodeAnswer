#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q(arr.begin(), arr.end());
        vector<int> res;
        while (k--)
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int m = primes.size();
        vector<int> dp(n + 1);
        vector<int> pointers(m, 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            vector<int> nums(m);
            int minNum = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                nums[j] = dp[pointers[j]] * primes[j];
                minNum = min(minNum, nums[j]);
            }
            dp[i] = minNum;
            for (int j = 0; j < m; j++)
            {
                if (minNum == nums[j])
                {
                    pointers[j]++;
                }
            }
        }
        return dp[n];
    }
};

int main()
{

    return 0;
}
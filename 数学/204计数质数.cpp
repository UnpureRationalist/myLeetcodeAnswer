#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    struct Comp
    {
        bool operator()(int i) const
        {
            return i != 0;
        }
    };

public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<int> record(n, 0);
        for (int i = 2; i < n; ++i)
            record[i] = i;
        int i = 2;
        while (i < n)
        {
            int num = record[i];
            for (int j = num * 2; j < n; j += num)
            {
                record[j] = 0;
            }
            ++i;
            while (i < n && record[i] == 0)
                ++i;
        }

        return count_if(record.begin(), record.end(), Comp());
    }
};

class Solution2
{
public:
    int countPrimes(int n)
    {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
            {
                ans += 1;
                if ((long long)i * i < n)
                {
                    for (int j = i * i; j < n; j += i)
                    {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution3
{
public:
    int countPrimes(int n)
    {
        vector<int> primes;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j)
            {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0)
                {
                    break;
                }
            }
        }
        return primes.size();
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(2) << endl;
    return 0;
}
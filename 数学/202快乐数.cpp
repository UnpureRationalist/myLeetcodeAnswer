#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution
{

private:
    unordered_set<int> cycleMembers = {4, 16, 37, 58, 89, 145, 42, 20};

public:
    int getNext(int n)
    {
        int totalSum = 0;
        while (n > 0)
        {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

public:
    bool isHappy(int n)
    {
        while (n != 1 && cycleMembers.find(n) == cycleMembers.end())
        {
            n = getNext(n);
        }
        return n == 1;
    }
};

class Solution2
{
public:
    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};

int main()
{

    return 0;
}
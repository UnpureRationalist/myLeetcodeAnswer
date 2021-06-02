#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size() + 1;
        int sum = n * (n - 1) / 2;
        for(auto num : nums)
            sum -= num;
        return sum;
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        if(iter == nums.end() || *iter > target)
            return 0;
        int count = 0;
        for(auto it = iter; it != nums.end() && *it == target ; ++it)
            ++count;
        return count;
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 输入的数组，1<=length(nums)<=100000，sum(nums) <= 1000000000
     * @param k int整型 需要满足整除条件的数
     * @return int整型
     */
    int bestSubCollection(vector<int> &nums, int k)
    {
        // write code here
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> acc(nums.size(), 0);
        int n = nums.size();
        acc[0] = nums[0];
        for (int i = 1; i < n; ++i)
            acc[i] = acc[i - 1] + nums[i];
        for (auto iter = acc.rbegin(); iter != acc.rend(); ++iter)
        {
            if ((*iter) % k == 0)
                return *iter;
        }
        return -1;
    }
};

int main()
{

    return 0;
}
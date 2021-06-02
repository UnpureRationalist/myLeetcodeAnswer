#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        if (k == 0)
            return;
        vector<int> temp(n);
        for (int i = 0; i < n; ++i)
        {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};

class Solution2
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        int count = __gcd(k, n);
        for (int start = 0; start < count; ++start)
        {
            int current = start;
            int prev = nums[start];
            do
            {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};

class Solution3
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

int main()
{

    return 0;
}
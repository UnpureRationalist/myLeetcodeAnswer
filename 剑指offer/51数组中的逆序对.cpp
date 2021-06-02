#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int solve(vector<int> &nums, vector<int> &temp, int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = solve(nums, temp, l, mid) + solve(nums, temp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
            {
                temp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else
            {
                temp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k)
        {
            temp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k)
        {
            temp[pos++] = nums[k];
        }
        copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp(n);
        return solve(nums, temp, 0, n - 1);
    }
};

class BIT
{
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static int lowbit(int x)
    {
        return x & (-x);
    }

    int query(int x)
    {
        int ret = 0;
        while (x)
        {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x)
    {
        while (x <= n)
        {
            ++tree[x];
            x += lowbit(x);
        }
    }
};

class Solution2
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> tmp = nums;
        // 离散化
        sort(tmp.begin(), tmp.end());
        for (int &num : nums)
        {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        // 树状数组统计逆序对
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            ans += bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}
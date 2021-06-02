#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> mer(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, mer.begin());
        nums1 = mer;
    }
};

int main()
{

    return 0;
}
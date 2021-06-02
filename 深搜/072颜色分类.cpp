#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> hash(3);
        for(auto elem : nums)
            ++hash[elem];
        int i = 0;
        int n = nums.size();
        while(i < n)
        {
            if(hash[0] > 0)
            {
                nums[i] = 0;
                --hash[0];
            }
            else if(hash[1] > 0)
            {
                nums[i] = 1;
                --hash[1];
            }
            else
            {
                nums[i] = 2;
                --hash[2];
            }
            ++i;
        }
    }
};

int main()
{

    return 0;
}
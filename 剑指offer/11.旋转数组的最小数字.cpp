#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int l = 0, r = numbers.size() - 1;
        int mid;
        while(l < r)
        {
            mid = l + (r-l)/2;
            if(numbers[mid] > numbers[r])
                l = mid + 1;
            else if(numbers[mid] < numbers[r])
                r = mid;
            else
                r--;
        }
        return numbers[l];
    }
};

int main()
{
    vector<int> v{3,5,1};
    Solution s;
    cout << s.minArray(v) << endl;
    return 0;
}
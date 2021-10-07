#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    float compute_Entropy(std::string s)
    {
        int cls[4] = {0};
        double ans = 0.0;
        int tot = s.length();
        for (int i = 0; i < s.length(); i++)
            cls[s[i] - 'A']++;
        for (int i = 0; i < 4; i++)
            if (cls[i])
            {
                ans -= 1.0 * cls[i] / tot * log2(1.0 * cls[i] / tot);
            }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.compute_Entropy("AABB") << endl;
    return 0;
}

/*
样例
content="AABB" 
content="AAAAAABBBB"
*/

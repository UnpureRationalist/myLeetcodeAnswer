#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        vector<int> hash(26);
        bool late = false;
        bool constant = true;
        int count = 0;
        for (auto c : s)
        {
            hash[c - 'A']++;
            if (c == 'L')
            {
                constant = true;
                ++count;
                if (count >= 3)
                {
                    late = true;
                }
            }
            else
            {
                constant = false;
                count = 0;
            }
        }
        return hash[0] < 2 && !late;
    }
};

int main()
{

    return 0;
}
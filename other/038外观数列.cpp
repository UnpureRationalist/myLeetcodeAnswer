#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string last("1");
        string now;
        for (int i = 1; i < n; ++i)
        {
            now.clear();
            int j = 0;
            auto length = last.length();
            while (j < length)
            {
                int count = 1;
                while (j < length && last[j] == last[j + 1])
                {
                    ++j;
                    ++count;
                }
                now += to_string(count) + last[j];
                ++j;
            }
            last = now;
        }
        return last;
    }
};

int main()
{

    return 0;
}
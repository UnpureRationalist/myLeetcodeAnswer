#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    int calBit(int n)
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    bool isLegalNumber(int hour, int minute, int turnedOn)
    {
        return (calBit(hour) + calBit(minute)) == turnedOn;
    }

    string trans(int hour, int min)
    {
        string res = to_string(hour) + ":";
        if (min == 0)
            return res + "00";
        if (min < 10)
            return res + "0" + to_string(min);
        return res + to_string(min);
    }

public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> res;
        for (int hour = 0; hour < 12; hour++)
        {
            for (int min = 0; min < 60; min++)
            {
                if (isLegalNumber(hour, min, turnedOn))
                {
                    res.push_back(trans(hour, min));
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}
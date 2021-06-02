#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss;
        ss.str(s);
        string temp;
        while(ss >> temp);
        return temp.length();
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseLeftWords(const string& s, int n)
    {
        return s.substr(n) + s.substr(0, n);
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int sum = 1;
        int i = n - 1;
        while (i >= 0)
        {
            sum += digits[i];
            digits[i] = sum % 10;
            sum = sum / 10;
            --i;
        }
        if (sum != 0)
            digits.insert(digits.begin(), sum);
        return digits;
    }
};

int main()
{

    return 0;
}
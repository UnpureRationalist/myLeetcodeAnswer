#include <iostream>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
    int guess(int num)
    {
    }

public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int val = guess(mid);
            switch (val)
            {
            case 1:
                left = mid + 1;
                break;
            case -1:
                right = mid + 1;
                break;
            default:
                return mid;
            }
        }
        return left;
    }
};

int main()
{

    return 0;
}
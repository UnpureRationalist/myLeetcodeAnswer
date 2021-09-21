#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string innerReverse(string s)
    {
        reverse(s.begin(), s.end());
        return s;
    }

    char invert(char c)
    {
        return 'z' - c + 'a';
    }

    string invert(string s)
    {
        string res = s;
        int n = s.length();
        for (int i = 0; i < n; ++i)
            res[i] = invert(s[i]);
        return res;
    }

    char getNum(int i)
    {
        return char(i + 'a' - 1);
    }

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回Sn的第k位字符
     * @param n int整型 Sn的n
     * @param k int整型 需要返回的字符下标位
     * @return char字符型
     */
    char findKthBit(int n, int k)
    {
        string numN("a");
        for (int i = 2; i <= n; ++i)
        {
            // cout << "num = " << numN << endl;
            string temp = numN;
            // cout << "invert = " << invert(temp) << endl;
            numN = temp + string(1, getNum(i)) + innerReverse(invert(temp));
        }

        return numN[k - 1];
    }
    /** 
     * strlen:
     * 1
     * 3
     * 7
     * 2n - 1
     */
};

int main()
{
    Solution s;
    // for(int i = 'a'; i <= 'z'; ++i)
    //     cout << s.invert(char(i)) << endl;
    // for(int i = 0; i <= 26; ++i)
    //     cout << "get : " <<  to_string(s.getNum(i)) << endl;
    int n, k;
    cin >> n >> k;
    cout << s.findKthBit(n, k) << endl;
    return 0;
}
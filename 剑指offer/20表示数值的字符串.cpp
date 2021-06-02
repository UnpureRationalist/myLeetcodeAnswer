#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
    请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
    例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
    但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
*/
/*
    问题分析：
    1、特殊字符：e 和 E，若包含一个 e 或者 E，则判断是否左右两侧都为数字（递归分治），其中右侧只能为整数（不含小数点）
    2、特殊字符：.  对包含小数点的字符串，只可以包含一个，且小数点右侧只能为普通数字串；左侧则可以包括符号
    3、特殊字符：+ 和 - ，对于一个普通数字（不包含e 或者 E），只可以出现一次
    4、base case：仅仅包含 0-9 的字符串


    作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/biao-shi-shu-zhi-de-zi-fu-chuan-by-leetcode-soluti/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
public:
    enum State
    {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END,
    };

    enum CharType
    {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL,
    };

    CharType toCharType(char ch)
    {
        if (ch >= '0' && ch <= '9')
        {
            return CHAR_NUMBER;
        }
        else if (ch == 'e' || ch == 'E')
        {
            return CHAR_EXP;
        }
        else if (ch == '.')
        {
            return CHAR_POINT;
        }
        else if (ch == '+' || ch == '-')
        {
            return CHAR_SIGN;
        }
        else if (ch == ' ')
        {
            return CHAR_SPACE;
        }
        else
        {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s)
    {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INITIAL, {
                                {CHAR_SPACE, STATE_INITIAL},
                                {CHAR_NUMBER, STATE_INTEGER},
                                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                                {CHAR_SIGN, STATE_INT_SIGN},
                            }},
            {STATE_INT_SIGN, {
                                 {CHAR_NUMBER, STATE_INTEGER},
                                 {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                             }},
            {STATE_INTEGER, {
                                {CHAR_NUMBER, STATE_INTEGER},
                                {CHAR_EXP, STATE_EXP},
                                {CHAR_POINT, STATE_POINT},
                                {CHAR_SPACE, STATE_END},
                            }},
            {STATE_POINT, {
                              {CHAR_NUMBER, STATE_FRACTION},
                              {CHAR_EXP, STATE_EXP},
                              {CHAR_SPACE, STATE_END},
                          }},
            {STATE_POINT_WITHOUT_INT, {
                                          {CHAR_NUMBER, STATE_FRACTION},
                                      }},
            {STATE_FRACTION, {
                                 {CHAR_NUMBER, STATE_FRACTION},
                                 {CHAR_EXP, STATE_EXP},
                                 {CHAR_SPACE, STATE_END},
                             }},
            {STATE_EXP, {
                            {CHAR_NUMBER, STATE_EXP_NUMBER},
                            {CHAR_SIGN, STATE_EXP_SIGN},
                        }},
            {STATE_EXP_SIGN, {
                                 {CHAR_NUMBER, STATE_EXP_NUMBER},
                             }},
            {STATE_EXP_NUMBER, {
                                   {CHAR_NUMBER, STATE_EXP_NUMBER},
                                   {CHAR_SPACE, STATE_END},
                               }},
            {STATE_END, {
                            {CHAR_SPACE, STATE_END},
                        }}};

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++)
        {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end())
            {
                return false;
            }
            else
            {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};

class Solution2
{
public:
    bool isNumber(string s)
    {
        //1、从首尾寻找s中不为空格首尾位置，也就是去除首尾空格
        int i = s.find_first_not_of(' ');
        if (i == string::npos)
            return false;
        int j = s.find_last_not_of(' ');
        s = s.substr(i, j - i + 1);
        if (s.empty())
            return false;

        //2、根据e来划分底数和指数
        int e = s.find('e');

        //3、指数为空，判断底数
        if (e == string::npos)
            return judgeP(s);

        //4、指数不为空，判断底数和指数
        else
            return judgeP(s.substr(0, e)) && judgeS(s.substr(e + 1));
    }

    bool judgeP(string s) //判断底数是否合法
    {
        bool result = false, point = false;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '+' || s[i] == '-')
            { //符号位不在第一位，返回false
                if (i != 0)
                    return false;
            }
            else if (s[i] == '.')
            {
                if (point)
                    return false; //有多个小数点，返回false
                point = true;
            }
            else if (s[i] < '0' || s[i] > '9')
            { //非纯数字，返回false
                return false;
            }
            else
            {
                result = true;
            }
        }
        return result;
    }

    bool judgeS(string s) //判断指数是否合法
    {
        bool result = false;
        //注意指数不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '+' || s[i] == '-')
            { //符号位不在第一位，返回false
                if (i != 0)
                    return false;
            }
            else if (s[i] < '0' || s[i] > '9')
            { //非纯数字，返回false
                return false;
            }
            else
            {
                result = true;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.isNumber("2e0") << endl;
    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss;
        ss.str(s);
        stack<string> stk;
        string temp;
        while (ss >> temp)
            stk.push(temp);
        string res;
        res = stk.top();
        stk.pop();
        while (!stk.empty())
        {
            res += " " + stk.top();
            stk.pop();
        }
        return res;
    }
};

class Solution2
{
public:
    string reverseWords(string s)
    {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start)
        {
            if (s[start] != ' ')
            {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0)
                    s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

int main()
{

    return 0;
}
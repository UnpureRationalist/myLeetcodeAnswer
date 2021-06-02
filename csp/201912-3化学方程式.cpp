#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

map<string, int> buff;

struct node
{
    string c;
    int n;
    node(string cc, int nn)
    {
        c = cc, n = nn;
    }
};
//这里是从后向前找的，因为这样统计元素个数比较方便
void mysplit(string x, int sign)
{
    int pre = 1, k = 0;
    if (isdigit(x[k]))
    {
        pre = 0;
        while (isdigit(x[k]))
        {
            pre = pre * 10 + x[k] - 48;
            ++k;
        }
    }
    string element = "";
    stack<int> before; //存储每一层次对应的系数
    //suff是层次对应的系数，tmp是单个或这个层次元素的系数
    int j = x.size() - 1, suff = 1, tmp = 1;
    while (j >= k)
    {
        if (isdigit(x[j]))
        {
            int times = 0;
            tmp = 0;
            while (isdigit(x[j]))
            {
                tmp += (x[j] - 48) * pow(10, times);
                ++times, --j;
            }
            ++j;
        }
        else if (x[j] == ')')
        {
            before.push(suff);
            suff *= tmp;
            tmp = 1;
        }
        else if (x[j] == '(')
        {
            suff = before.top();
            before.pop();
        }
        else if (islower(x[j]))
            element.insert(element.begin(), x[j]);
        else if (isupper(x[j]))
        {
            element.insert(element.begin(), x[j]);
            if (sign == 0)
                buff[element] += tmp * suff * pre;
            else if (sign == 1)
                buff[element] -= tmp * suff * pre;
            tmp = 1;
            element = "";
        }
        --j;
    }
}

void deal(string part, int sign)
{
    vector<string> box;
    string tmp = "";
    for (int i = 0; i < part.size(); ++i)
    {
        if (part[i] == '+')
        {
            box.push_back(tmp);
            tmp = "";
        }
        else
            tmp.push_back(part[i]);
    }
    box.push_back(tmp);
    for (int i = 0; i < box.size(); ++i)
        mysplit(box[i], sign);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        buff.clear();
        string equation;
        cin >> equation;
        int k = 0;
        while (equation[k] != '=')
            ++k;
        string l = equation.substr(0, k);
        string r = equation.substr(k + 1, equation.size() - k - 1);
        deal(l, 0);
        deal(r, 1);
        map<string, int>::iterator it;
        int sign = 0;
        for (it = buff.begin(); it != buff.end(); ++it)
        {
            if (it->second != 0)
            {
                sign = 1;
                break;
            }
        }
        if (sign)
            cout << "N" << endl;
        else
            cout << "Y" << endl;
    }
    return 0;
}

// #include <iostream>
// #include <string>
// #include <stack>
// #include <map>
// #include <vector>
// #include <cstring>
// #include <cmath>
// using namespace std;

// /*

// 11
// 5
// H2+O2=H2O
// 2H2+O2=2H2O
// H2+Cl2=2NaCl
// H2+Cl2=2HCl
// CH4+2O2=CO2+2H2O
// CaCl2+2AgNO3=Ca(NO3)2+2AgCl
// 3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
// 3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
// 4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
// 4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
// Cu+As=Cs+Au

// */

// pair<string, string> split(const string &s)
// {
//     int n = s.length();
//     int i = 0;
//     for (; i < n && s[i] != '='; ++i)
//         ;
//     string left = s.substr(0, i);
//     string right = s.substr(i + 1);
//     return pair<string, string>(left, right);
// }

// vector<string> resplit(const string &s)
// {
//     int n = s.length();
//     int i = 0;
//     vector<string> res;
//     while (i < n)
//     {
//         int j = i + 1;
//         while (j < n && s[j] != '+')
//             ++j;
//         string temp = s.substr(i, j - i);
//         res.push_back(temp);
//         i = j + 1;
//     }
//     return res;
// }

// bool isLower(char c)
// {
//     if(c >= 'a' && c <= 'z')
//         return true;
//     return false;
// }

// map<string, int> getElem(const string &s)
// {
//     vector<string> strs = resplit(s);
//     map<string, int> mp;
//     for (auto &str : strs)
//     {
//         // cout << "str = " << str << endl;
//         int n = str.length();
//         // 处理开头数字
//         int i = 0;
//         while (i < n && isdigit(str[i]))
//             ++i;
//         int mult = 1;
//         if (i != 0)
//         {
//             string num = str.substr(0, i);
//             mult = atoi(num.c_str());
//         }
//         // 处理元素
//         map<string, int> one; // 记录一个化学式原子数目
//         stack<string> stk;
//         while (i < n)
//         {
//             // cout << "i = " << i << endl;
//             if (isalpha(str[i])) // 若为字母
//             {
//                 int j = i + 1;
//                 // cout <<"j = " << j <<  "  s[j] = " << s[j] << endl;
//                 if (j < n && isLower(s[j])) // 若为小写字母，说明属于同一元素，指针前移
//                     ++j;
//                 string elem = str.substr(i, j - i); // 元素符号
//                 // cout << "elem = " << elem << endl;
//                 i = j;
//                 int count = 1;
//                 while (j < n && isdigit(j))
//                     ++j;
//                 // cout << "j = " << j << "  str[j] = " << str[j] << endl;
//                 if (i < n && isdigit(str[i]))
//                 {
//                     string num = str.substr(i, j - i + 1);
//                     count = atoi(num.c_str());
//                     // cout << "j = " << j << "  str[j] = " << str[j] << endl;
//                     // cout << "num = " << num <<endl;
//                     // cout << "count = " << count << endl;
//                     // cout << "before str[i] = " << str[i] << endl;

//                     i = j + 1; // 移动指针

//                     // cout << "after  str[i] = " << str[i] << endl;
//                 }
//                 one[elem] += count;
//             }
//             else // 为 '(' or ')'
//             {
//             }
//         }
//         // cout << "one.size() = " << one.size() << endl;
//         for (auto &elem : one)
//         {
//             mp[elem.first] += elem.second * mult;
//         }
//     }
//     // cout << endl << endl;
//     return mp;
// }

// bool judge(const string &s)
// {
//     pair<string, string> res = split(s);
//     auto left = getElem(res.first);
//     auto right = getElem(res.second);

//     // for(auto &elem : left)
//     //     cout << elem.first << "  " << elem.second << endl;
//     // cout << endl;
//     // for(auto &elem : right)
//     //     cout << elem.first << "  " << elem.second << endl;
//     // cout << endl;
//     // cout << "left.size() = " << left.size() << "  right.size() = " << right.size() << endl;
//     if (left.size() != right.size())
//         return false;
//     auto it1 = left.begin();
//     auto it2 = right.begin();
//     while (it1 != left.end())
//     {
//         // cout << "iter1 : " << it1->first << "  " << it1->second << "  iter2 : " << it2->first << "  " << it2->second << endl;
//         if (it1->first == it2->first && it1->second == it2->second)
//         {
//             ++it1;
//             ++it2;
//             continue;
//         }
//         else
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     int n = 0;
//     cin >> n;
//     string s;
//     while (n--)
//     {
//         cin >> s;
//         if (judge(s))
//             cout << "Y" << endl;
//         else
//             cout << "N" << endl;
//     }
//     return 0;
// }
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isPrim(long long n)
{
    if (n == 2)
        return true;
    if (n <= 1)
        return false;
    if (n == 1 || (n % 2) == 0)
        return false;
    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

string s;
long long n;

int main()
{
    cin >> s >> n;
    int length = s.length();
    vector<long long> count(26, 0);
    for (auto c : s)
        ++count[c - 'a'];    // 计算字符串中字符数量
    auto times = n / length; // 倍数
    auto left = n % length;  // 余数
    for (int i = 0; i < 26; ++i)
        count[i] *= times;
    for (int i = 0; i < left; ++i)
        ++count[s[i] - 'a'];
    long long max_val = count[0], min_value = (1 << 30);
    for (auto &num : count)
    {
        if (num != 0)
        {
            if (num > max_val)
                max_val = num;
            if (num < min_value)
                min_value = num;
        }
    }
    auto res = max_val - min_value;
    bool b = isPrim(res);
    cout << (b ? "Yes" : "No") << endl;
    cout << res << endl;
    return 0;
}
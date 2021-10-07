#include <string>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 5;
char s[N];
int cls[4]; //存放 ABCD 出现多少次
double ans;
int main()
{
    cin.getline(s, 100000);             //读入 content="AABB"  //solution不用好像读入
    int tot = strlen(s);                //字符串长
    for (int i = 0; i < strlen(s); i++) //不用读入那记得改改起始位置
        cls[s[i] - 'A']++;              //A出现次数存到cls[0]  B到cls[1] ..直到 D
    for (int i = 0; i < 4; i++)
        if (cls[i])
        { //防止出现log(0)
            ans -= 1.0 * cls[i] / tot * log2(1.0 * cls[i] / tot);
        }
    printf("%.2lf", ans);
    return 0;
}
/*
样例
content="AABB" 
content="AAAAAABBBB"
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct Node
{
    int num = 0;
    unsigned long long sum = 0;
};
vector<Node> a(1000000);
int bitsum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    set<unsigned long long> s;
    for (int i = 1; i <= 1000000; i++)
    {
        int wei = bitsum(i);
        a[wei].num++;
        a[wei].sum += i;
        if (a[wei].num == n)
        {
            s.insert(a[wei].sum);
        }
    }
    cout << *(s.begin());
    return 0;
}
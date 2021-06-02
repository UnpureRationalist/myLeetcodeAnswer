#include <iostream>
using namespace std;
//  澡盆里最少放几只鸭子后，便无法再向其中放入更多的鸭子
int A,B,a,b;
int main()
{
    cin >> A >> B >> a >> b;
    int row = A / (2*a);
    int col = B / (2*b);
    int rowmd = A % (2*a);
    if(rowmd >= a)
        row++;
    int colmd = B % (2*b);
    if(colmd >= b)
        col++;
    cout << row * col << endl;
    return 0;
}
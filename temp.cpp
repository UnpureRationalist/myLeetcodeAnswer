#include <stdio.h>

int a[] = {12, 3, 4};

int main()
{
    void (*f)() = (void (*)(void))(a);
    f(); // 输出 hello world 并且正常返回结束
    return 0;
}
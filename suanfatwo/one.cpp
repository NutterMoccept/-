//函数基础知识  函数的声名、定义和调用 静态变量

#include <iostream>

using namespace std;

//函数声名
int foo(int n);

//函数定义
int foo(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

int output(void)
{
    static int cnt = 0; //仅在函数第一次调用时候执行  静态变量 等于在函数内部开了只有该函数可以使用的全局变量
    cnt++; 
    cout << "call:" << cnt << "times" << endl;
    return cnt;
}

int main()
{
    output();
    output();
    output();
    output();
    output();
    int t = foo(5);
    cout << t << endl;
    return 0;
}
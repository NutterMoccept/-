//函数基本知识   非引用类变量
#include <iostream>

using namespace std;

int max(int &x, int &y)
{
    x = 10, y = 20; //当初始化一个非引用类的变量时，初始值被拷贝变量。此时，对变量的改动不会影响初始值
    return x > y ? x : y;
}

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << max(a, b) << endl;

    cout << a << ' ' << b << endl;
    return 0;
}
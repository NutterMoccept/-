//函数基础知识 三维数组
#include <iostream>

using namespace std;

void output(int n, int m, int a[3][3])// 输出二维数组的元素
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }// 将二维数组的所有元素设置为1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = 1;
        }
    }
}

int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
// 调用output函数，传递二维数组a的信息
    output(3, 3, a);

    cout << endl;
// 输出经过output函数处理后的二维数组
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
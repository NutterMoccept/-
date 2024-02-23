//函数基础知识 三维数组
#include <iostream>

using namespace std;

void output(int n, int m, int a[3][3])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
            a[i][j] = 1;
        }
        cout << endl;
    }
}
int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},

    };
    output(3, 3, a);

    puts("");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}
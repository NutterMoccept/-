#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

int n, m;
int s[N][N]; //二维数组存储矩阵的值

int main()
{
    int cnt, R;
    cin >> cnt >> R;
    R = min(5001, R); // R取值的上限限制在5001

    n = m = R; //初始化矩阵的行列数为R

    while (cnt--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        n = max(n,x),m = max(m,y);
        s[x][y] += w;
    }
// 预处理前缀和
// s[i][j]表示从起点(0,0)到达坐标(i, j)的矩形内的元素和
// 通过累加前一行、前一列和前一行前一列的值，即可得到当前坐标的元素和

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];

    int res = 0;

// 枚举所有边长是R的矩形，枚举(i, j)为右下角
// 通过计算前缀和可以得到当前矩形内的元素和
// 减去左上角矩形内的元素和，即可得到当前矩形的元素和
    for (int i = R; i <= n; i++)
        for (int j = R; j <= m; j++)
            res = max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);

    cout << res << endl;

    return 0;
}
//位运算
#include <iostream>

using namespace std;

/*
int main()
{
    int n = 10;
    for (int k = 3; k >= 0; k--)
        cout << (n >> k & 1);

    return 0;
}
*/
int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n = 10;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;

        int res = 0;
        while (x)
            x-= lowbit(x), res++; //每次减去x的最后一位ie
        cout << res <<' ';
    }
    return 0;
}
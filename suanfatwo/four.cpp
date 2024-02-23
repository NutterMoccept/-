//高精度数相加    第一种写法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
// 函数用于将两个整数表示的大数相加，返回结果的大数表示
vector<int> add(vector<int> &A, vector<int> &B)
{
    // 确保A的长度不小于B的长度
    if (A.size() < B.size())
        return add(B, A);

    // 创建结果的大数表示
    vector<int> C;
    // 进位标志
    int t = 0;
    // 逐位相加
    for (int i = 0; i < A.size(); i++)
    {
        // 当前位的结果等于A当前位和B当前位的数字相加再加上进位
        t += A[i];
        if (i < B.size())
            t += B[i];

        // 将结果的个位放入C中
        C.push_back(t % 10);
        // 更新进位
        t /= 10;
    }
    // 如果还有进位，将进位的最高位放入C中
    if (t)
        C.push_back(t);
    // 返回结果的大数表示
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    // 输入两个大整数
    cin >> a >> b;

    // 将字符串表示的大整数转换为大数表示，倒序存储在向量中
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    // 将两个大数相加，得到结果的大数表示
    vector<int> C = add(A, B);
    // 输出结果
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;

    return 0;
}


*/
/*

//高精度数相加    第二种写法
#include <iostream>
#include <vector>

using namespace std;
// 函数用于将两个整数表示的大数相加，返回结果的大数表示
vector<int> add(vector<int> &A, vector<int> &B)
{
    // 确保A的长度不小于B的长度
    if (A.size() < B.size())
        return add(B, A);

    // 创建结果的大数表示
    vector<int> C;
    // 进位标志
    int carry = 0;
    // 逐位相加
    for (int i = 0; i < A.size(); i++)
    {
        // 当前位的结果等于A当前位和B当前位的数字相加再加上进位
        int sum = A[i] + (i < B.size() ? B[i] : 0) + carry;
        // 将结果的个位放入C中
        C.push_back(sum % 10);
        // 更新进位
        carry = sum / 10;
    }
    // 如果还有进位，将进位的最高位放入C中
    if (carry)
        C.push_back(carry);
    // 返回结果的大数表示
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    // 输入两个大整数
    cin >> a >> b;

    // 将字符串表示的大整数转换为大数表示，倒序存储在向量中
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    // 将两个大数相加，得到结果的大数表示
    vector<int> C = add(A, B);
    // 输出结果
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;

    return 0;
}

*/
/*
//高精度减法
using namespace std;

bool cmp(vector<int> &A, vector<int> &B)  //比较两数的大小
{
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i -- )
        if (A[i] != B[i])
            return A[i] > B[i];

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;  //对借位进行判断
    } 

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    vector<int> C;  //设置的商位

    if (cmp(A, B)) C = sub(A, B);
    else C = sub(B, A), cout << '-';

    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}

*/

//高精度乘法
/*
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }   //一位一位的求

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}


int main()
{
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    auto C = mul(A, b);  

    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);

    return 0;
}

*/

//高精度除法
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string a;
    vector<int> A;

    int B;
    cin >> a >> B;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    int r;
    auto C = div(A, B, r);

    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];

    cout << endl << r << endl;

    return 0;
}


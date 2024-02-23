#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> A, vector<int> B)
{
    //确保A的长度不小于B的长度
    if (A.size() < B.size())
        return add(B, A);
    //创建结果的大数表示
    vector<int> C;
    //进位标志
    int t = 0;
    //逐位相加
    for (int i =0;i<A.size();i++){
         // 当前位的结果等于A当前位和B当前位的数字相加再加上进位
         t+=A[i];
         if(i<B.size())
            t+=B[i];
        //将结果的个位放入C中
        C.push_back(t%10);
        //更新进位
        t/=10;
    }
    //如果还有进位，将进位的最高位放入C中
    if (t)
        C.push_back(t);
    return C;
}

int main()
{
    //输入两个相加的正整数
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    //将字符串表示的大整数转换为大数表示，倒叙存储在向量中
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    //将两个大数相加，得到的结果大数表示
    vector<int> C = add(A, B);
    //输出结果
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;
    return 0;
}
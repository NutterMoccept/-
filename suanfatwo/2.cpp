//找出一个数的所有质数

#include <iostream>

using namespace std;
/*
int main(){
    int n,s;
    cin>>n;
    for(int i=2;i<=n;i++){
        int flag = 1;
        for(int j =2;j*j<=i;j++){//如果在j的值大于i的平方根之前找到了i的因数，则i不是质数
            if(i%j==0){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            cout<<i<<" ";
            s++;
            if(s%5==0)cout<<endl;
        }
    }
    cout<<endl;
    return 0;
}
*/
/*int main(){
    int n,s;
    cin>>n;
    while(n>1){
        int flag = 1;
        for(int i=2;i<=n;i++){
            for(int j=2;j*j<=i;j++){
                if(n%j==0){
                    flag = 0;
                    break;
                }
            }
            if(flag==1&&n%i==0){
                cout<<i<<" ";
                n=n/i;
            }
        }
    }
    cout<<endl;
    return 0;

}
*/
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n != 1)
        cout << n << " ";
    cout << endl;
    return 0;
}
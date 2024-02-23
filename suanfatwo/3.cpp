#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
/*
int main(){
    long long n,m,a1=0,a2=0;
    cin>>n>>m;
    for(int i=1;i<<n;i++){
        for(int j=1;j<<m;j++){
            if(j==j) a1+=(n-i+1)*(m-j+1);
            else a2+=(n-i+1)*(m-j+1);
        }
    }
    cout <<a1<<" "<<a2<<endl;
    return 0;

}
*/
/*
int dp[10010];
int main(){
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n]<<endl;
    return 0;
}
*/
/*
int n;
void dfs(int u,int state){
    if(u==n){
        for(int i=0;i<n;i++)
        if(state>>i&1)
            cout <<i+1<<" ";
        cout <<endl;
        return;
    }
    dfs(u+1,state);
    dfs(u+1,state+(1<<u));
}

int main(){
    cin>>n;
    dfs(0,0);
    return 0;
}
*/

const int N=10;

int n;
int state[N];// 0 表示还没放数量，1~n表示放了那个数
bool used[N];// true表示用过，false表示还没用过

void dfs(int u){
   if(u>n) //边界
   {
    for(int i=1;i<=n;i++) cout<<state[i]<<" "; //打印方案
    puts("");

    return; //返回上一层
   }

   //一次枚举每个分支，即当前位置可以填哪些数
   for(int i=1;i<=n;i++)
    if(!used[i]) //如果这个数还没用过，则可以填
    {
        state[u]=i; 
        used[i]=true; //标记为已用
        dfs(u+1); //进入下一层

        //恢复现场
        state[u]=0;
        used[i]=false;
    }
}

int main(){
    scanf("%d",&n);

    dfs(1);

    return 0;
}
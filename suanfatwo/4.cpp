//费解的开关

#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1000000;

char g[10][10];
int dx[5] = {0,-1,0,1,0},dy[5]={0,0,1,0,-1};

void turn(int x,int y)
{
    for(int i=0;i<5;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=0&&a<5&&b>=0&&b<5) g[a][b]^=1;
    }

}


int work(){
    int ans = INF;
    for(int k=0;k<1<<5;k++)
    {//枚举所有状态，1<<5表示5个灯的所有可能状态，即0到31的二进制数
        int res = 0;
        char backup[10][10];
        memcpy(backup,g,sizeof(g));  
        for(int j=0;j<5;j++)
            if(k>>j&1)
            {
                res++;
                turn(0,j);//判断第一行的32状态，确定后就不再按
            }
        for(int i =0;i<4;i++)
            for(int j=0;j<5;j++)
                if(g[i][j]== '0')
                {
                    res++;
                    turn(i+1,j);
                }    //按好前4行的状态，按好就不能再按了

        bool is_successful =true;
        for(int j =0;j<5;j++)
            if(g[4][j]=='0')
            {
                is_successful = false;
                break;
            }  //枚举（遍历）前四行是否都为1
        if(is_successful) ans = min(ans,res);

        memcpy(g,backup,sizeof(g));
    }
    if(ans>6) ans= -1;
    return ans;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<5;i++) cin>>g[i]; //一次输入一行
        cout << work() << endl;

    }
    return 0;

}
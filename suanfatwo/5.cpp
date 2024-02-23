/*#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int s[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {   
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x; //由于数组下标从 0 开始，因此我们需要将 i 减 1   
    }
    //i=1,2,3,4.....j-1  j-1是第一个切的位置，j是第二个切的位置
    if(s[n]%3) puts("0");
    else{
        LL res = 0,cnt= 0;
        for(int j=2;j<n;j++)
        {
            if(s[j-1]==s[n]/3) cnt++;
            if(s[j]==s[n]/3*2) res+=cnt;
         }
         printf("%lld\n",res);
    }
    return 0;
}
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int s[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){

        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
    if(s[n]%3) puts("0");
    else{
        LL res=0,cnt=0; //res表示当前的方案数 cnt表示当前j变化的状态
        for(int j=2;j<n;j++){
            if(s[j-1]==s[n]/3) cnt++;
            if(s[j]==s[n]/3*2) res+=cnt;
        }
        printf("%lld\n",res);
    }
    return 0;

}


//k陪区间
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, k;
LL s[N], cnt[N];

int main()
{

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];  //前缀和 
    }

    LL res = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        //  printf("%d:%lld\n",i,s[i]%k,cnt[s[i]%k]);  检查错误
        res += cnt[s[i] % k]; 
        cnt[s[i] % k]++;   //cnt 
    }
    printf("%lld\n", res);

    return 0;
}
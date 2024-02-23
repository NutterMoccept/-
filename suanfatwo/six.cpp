#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0 && i % 3 != 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
*/

int main(){
    int n;
    cin >>n;
    vector<int> S(n);
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    sort(S.begin(),S.end());
    
    int count =0;
    
    count += (S[0] * S[1] * S[2]);
    count += (S[n-1]) *S[n-2] * S[n-3];
    cout<<count<<endl;
    return 0;
}
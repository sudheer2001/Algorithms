#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 
int n;
int dp[100100];
int h[100100];

int rec(int l){
    if(l<1){return 1e5;}
    if(l==1){return 0;}
    if(dp[l]!=-1){return dp[l];}
    int ans=min((rec(l-1)+abs(h[l]-h[l-1])),(rec(l-2)+abs(h[l]-h[l-2])));
    return dp[l]=ans;

}


void solve()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin>>h[i];
    }
    cout<<rec(n)<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}
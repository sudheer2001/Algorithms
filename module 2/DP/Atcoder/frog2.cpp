#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 

int n,k;
int dp[100100];
int h[10100];

int rec(int l){
    if(l<1){return 1e9;}
    if(l==1){return 0;}
    if(dp[l]!=-1){return dp[l];}
    int ans=1e9;
    for(int i=1;i<=k;i++){
        if(l-i>=1)ans=min(ans,(rec(l-i)+abs(h[l]-h[l-i])));
    }
    return dp[l]=ans;
}


void solve()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
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
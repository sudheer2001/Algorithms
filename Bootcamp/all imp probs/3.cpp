#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 

void solve()
{
    int n;cin>>n;
    if(n==1){cout<<"NO\n";return;}
    if(n==2){cout<<"YES\n";return;}
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0){cout<<"NO\n";;return;}
    }
    {cout<<"YES\n";}
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}
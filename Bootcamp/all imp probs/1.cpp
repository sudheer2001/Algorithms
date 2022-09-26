#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 

void solve()
{
    int n;cin>>n;
    int total=0;
    while(n--){
        int temp;cin>>temp;
        total^=temp;
    }
    cout<<total<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}
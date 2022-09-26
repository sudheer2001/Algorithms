#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long int 

void solve()
{
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans=0;
    for (int i = 0; i < n-1; i++)
    {
        ans+=upper_bound(arr,arr+n,arr[i]+k)-lower_bound(arr,arr+n,arr[i]+k);
    }
    cout<<ans<<endl;
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}
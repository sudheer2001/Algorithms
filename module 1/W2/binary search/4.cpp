#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
int n,k;
int arr[100100]={0};

bool check(int x){
	for (int i = 0; i <=n-x ; ++i)
	{
		if((x-arr[i+x]+arr[i])<=k){return 1;}
		continue;
	}
	return 0;
}

void solve(){
	cin>>n>>k;
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 1; i <=n; ++i)
	{
		arr[i]+=arr[i-1];
		// cout<<arr[i]<<' ';
	}
	// cout<<endl;
	int lo=1,hi=n,ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		// cout<<k;
		if(check(mid)){
			ans=mid;
			lo=mid+1;
		}else{
			hi=mid-1;
		}
	}
	// cout<<endl;

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


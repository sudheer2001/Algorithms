#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
// int freq[100100];

void solve(){
	int n,k;cin>>n>>k;
	int arr[n]={0};
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	ll ans=0;
	int head=-1,tail=0,sum=0;

	while(tail<n){
		while(head<n-1 && (sum+arr[head+1]<=k)){
			head++;
			sum+=arr[head];
		}
		ans+=head-tail+1;

		if(head>=tail){
			sum-=arr[tail];
			tail++;
		}
		else{
			tail++;
			head=tail-1;
		}

	}

	cout<<ans<<endl;
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


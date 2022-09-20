#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

void solve(){
	int n,target;cin>>n>>target;
	int arr[n];
	for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}	
	sort(arr,arr+n);
	int ans=(int)1e18;int sum=0;
	for (int j = 1; j <n-1 ; ++j)
	{
		int i=0,k=n-1;
		while(i<j && k>j){
			sum=arr[i]+arr[j]+arr[k];
			if(sum==target){
				cout<<0<<endl;return;
			}
			else if(sum<target){
				ans=min(ans,abs(sum-target));
				i++;
			}
			else{
				ans=min(ans,abs(sum-target));
				k--;
			}
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


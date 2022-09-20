#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int freq[1001000];
int distinct;

ll ansss(int arr[],int n, int k){
	int tail=0,head=-1;
	ll ans=0;
	while(tail<n){
		while(head<n-1 && ((freq[arr[head+1]]>0 && distinct<=k) ||(freq[arr[head+1]]==0 && distinct<k) )){
			head++;
			if(freq[arr[head]]==0)distinct++;
			freq[arr[head]]++;
		}
		// cout<<tail<<' '<<head<<endl;
		// cout<<distinct<<endl;

		ans+=head-tail+1;

		if(head>=tail){
			if(freq[arr[tail]]==1)distinct--;
			freq[arr[tail]]--;
			tail++;
		}
		else{
			tail++;
			head=tail-1;
		}
	}

	return ans;
}

void solve(){
	int n,k;cin>>n>>k;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	ll ans=ansss(arr,n,k)-ansss(arr,n,k-1);	

	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


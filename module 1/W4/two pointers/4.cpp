#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
int freq[100100];

void solve(){
	int n;cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	unordered_set<int> st(arr,arr+n);
	int total=(int)st.size();

	int tail=0,head=-1,ans=100000,distinct=0;
	while(tail<n){
		while(head<n-1 &&  distinct<total){
			head++;
			if(freq[arr[head]]==0)distinct++;
			freq[arr[head]]++;
		}
		// cout<<tail<<' '<<head<<endl;
		// cout<<distinct<<endl;
		if(distinct==total)	ans=min(ans,head-tail+1);

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
	cout<<ans<<endl;

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


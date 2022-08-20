#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
int freq[1000100];
int n;

void solve(){
	int d;cin>>n>>d;
	int arr[n];
	for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}	
	int tail=0,head=-1,penalty=0,ans=1000000;
	while(tail<n-d+1){
		while(head-tail+1<d){
			head++;
			if(freq[arr[head]]==0){penalty++;}
			freq[arr[head]]++;
		}
		ans=min(ans,penalty);
		if(head>=tail){
			if(freq[arr[tail]]==1){penalty--;}
			freq[arr[tail]]--;
			tail++;
		}else{
			tail++;
			head=tail-1;
		}
	}
	for (int i = tail; i < n; ++i)
	{
		freq[arr[i]]=0;
	}
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
int n,k;
map<int,int> mp;

bool check(int x){
	int count=0;
	auto it=mp.begin();
	while(it!=mp.end()){
		count+=min(it->second,x);
		it++;
	}
	return count>=k*x;
}


void solve(){
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		mp[x]++;
	}
	int lo=0,hi=n/k;
	int ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(check(mid)){
			ans=mid;
			lo=mid+1;
		}else{
			hi=mid-1;
		}

	}
	cout<<ans<<endl;
	mp.clear();

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


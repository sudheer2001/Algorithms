#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
int n,s;

bool check(int x){
	string st=to_string(x);
	int sod=0;
	for (int i = 0; i < st.length(); ++i)
	{
		sod+=st[i]-'0';
	}
	if(x-sod<s){return 1;}
	return 0;
}


void solve(){
	cin>>n>>s;
	int lo=0,hi=n;
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
	cout<<n-ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


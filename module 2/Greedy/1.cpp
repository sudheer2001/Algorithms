#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

void solve(){
	int x,y;cin>>x>>y;
	int count=0;
	while(y>x){
		if(y%2){y++;count++;}
		else{y/=2;count++;}
	}
	count+=x-y;
	cout<<count<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


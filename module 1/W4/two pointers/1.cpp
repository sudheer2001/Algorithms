#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

void solve(){
	string s;cin>>s;

	int round=pow(10,s.length()-1);
	cout<<stoi(s)-round<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


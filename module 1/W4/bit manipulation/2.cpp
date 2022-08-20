// Enter your code below 

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long

void solve(){
	int q;cin>>q;
	int num=0;
	while(q--){
		int x;cin>>x;
		if(x==1){
			int i;cin>>i;
			cout<<((num>>i)&1)<<endl;
		}
		if(x==2){
			int i;cin>>i;
			num=num | (1<<i);
		}
		if(x==3){
			int i;cin>>i;
			num=num&(~(1<<i));
		}
		if(x==4){
			int i;cin>>i;
			num=num^(1<<i);
		}
		if(x==5){
			if(__builtin_popcountll(num)==60){cout<<1<<endl;}
			else{cout<<0<<endl;}
		}
		if(x==6){
			if(num!=0){cout<<1<<endl;}
			else{cout<<0<<endl;}
		}
		if(x==7){
			if(num==0){cout<<1<<endl;}
			else{cout<<0<<endl;}
		}
		if(x==8){
			cout<<__builtin_popcountll(num)<<endl;
		}
		if(x==9){
			cout<<num<<endl;
		}	

	}	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}
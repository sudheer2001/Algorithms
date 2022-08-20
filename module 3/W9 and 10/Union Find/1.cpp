#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

struct unionfind{
	vector<int>rank,par;
	unionfind(int n){
		rank.resize(n,1);
		par.resize(n);
		for (int i = 0; i < n; ++i)
		{
			par[i]=i;
		}
	}

	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}

	void merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		if(rank[x]>=rank[y]){
			rank[x]+=rank[y];
			par[y]=par[x];
		}else{
			rank[y]+=rank[x];
			par[x]=par[y];
		}
	}
	int same(int x,int y){
		return find(x)==find(y);
	}

};



void solve(){
	int n,q;cin>>n>>q;
	unionfind UF(n);
	for (int i = 0; i < q; ++i)
	{
		int com,x,y;cin>>com>>x>>y;
		if(com==0){
			UF.merge(x,y);
		}else{
			cout<<UF.same(x,y)<<endl;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


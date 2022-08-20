#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

struct unionfind{
	int ans=0;vector<int>par,rank;

	unionfind(int n){
		par.resize(n+1);
		rank.resize(n+1,1);
		for (int i = 0; i < n+1; ++i)
		{
			par[i]=i;
		}
	}

	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}

	void merge(int x,int y,int d){
		x=find(x);y=find(y);
		if(x==y)return;
		if(rank[x]>=rank[y]){
			ans+=(rank[x]*rank[y])*d;
			rank[x]+=rank[y];
			par[y]=x;
		}else{
			ans+=(rank[x]*rank[y])*d;
			rank[y]+=rank[x];
			par[x]=y;
		}
	}
};


void solve(){
	int n;cin>>n;
	unionfind UF(n);
	priority_queue<pair<int,pair<int,int>>>pq;
	for (int i = 0; i < n-1; ++i)
	{
		int a,b,c;cin>>a>>b>>c;
		pq.push({c,{a,b}});
	}

	while(!pq.empty()){
		pair<int,pair<int,int>> x=pq.top();pq.pop();
		UF.merge(x.second.second,x.second.first,x.first);
		// cout<<UF.ans<<"--";
	}

	cout<<UF.ans<<endl;


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


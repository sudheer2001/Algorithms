#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

struct unionfind{
	int cmp;
	vector<int>rank,par;
	unionfind(int n){
		cmp=n;
		rank.resize(n+1,1);
		par.resize(n+1);
		for (int i = 1; i < n+1; ++i)
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
			par[y]=x;
		}else{
			rank[y]+=rank[x];
			par[x]=y;
		}
		cmp--;

	}

	int compcount(){
		return cmp;
	}
};


void solve(){
	int n,m,q;cin>>n>>m>>q;
	vector<pair<int,int>>edges;
	edges.resize(m+1);
	for (int i = 1; i <= m; ++i)
	{
		int x,y;cin>>x>>y;
		edges[i]={x,y};	
	}
	vector<bool>exist(m+1,true);

	vector<pair<int,int>>query;
	for (int i = 0; i < q; ++i)
	{
		int x;cin>>x;
		if(x==1){
			int y;cin>>y;
			query.push_back({1,y});
			exist[y]=false;
		}else{
			query.push_back({2,0});
		}
	}
	unionfind UF(n);
	for (int i = 1; i <m+1 ; ++i)
	{
		if(exist[i]){
			UF.merge(edges[i].first,edges[i].second);
		}
	}
	reverse(query.begin(), query.end());
	vector<int>ans;
	for (int i = 0; i < q; ++i)
	{
		if(query[i].first==1){
			UF.merge(edges[query[i].second].first,edges[query[i].second].second);
		}else{
			ans.push_back(UF.compcount());
		}
	}
	for (auto it = ans.rbegin(); it != ans.rend(); ++it)
	{
		cout<<*it<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


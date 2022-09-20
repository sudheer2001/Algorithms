#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<vector<int>>v;
vector<int>depth;
vector<int>parent;

void dfs(int node,int par,int dep){
	parent[node]=par;depth[node]=dep;
	for(auto child:v[node]){
		if(child!=par){
			dfs(child,node,dep+1);
		}
	}
}



void solve(){
	int n;cin>>n;	
	v.resize(n+1);depth.resize(n+1);parent.resize(n+1);
	for (int i = 0; i < n-1; ++i)
	{
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,1,0);
	int maxdp=-1,occ=-1;
	for (int i = 1; i <= n; ++i)
	{
		if(depth[i]>maxdp){maxdp=depth[i];occ=i;}
	}
	dfs(occ,occ,0);
	maxdp=-1;
	for (int i = 1; i <= n; ++i)
	{
		if(depth[i]>maxdp){maxdp=depth[i];}
	}
	cout<<maxdp<<endl;


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


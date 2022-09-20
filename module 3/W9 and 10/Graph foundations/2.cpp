#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<vector<int>> v;
vector<int>col;
vector<int>parent;
int is_cylce=0;

void dfs(int node,int par){
	col[node]=2;
	parent[node]=par;
	for(auto child:v[node]){
		if(child==par){continue;}
		if(col[child]==1){
			dfs(child,node);
		}
		else if(col[child]==2){
			is_cylce=1;
		}
	}
}


void solve(){
	int n,m;cin>>n>>m;
	v.resize(n+1);col.assign(n+1,1);
	parent.assign(n+1,0);
	for (int i = 0; i < m; ++i)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i < n+1; ++i)
	{
		if(col[i]==1){dfs(i,0);}
	}
	if(is_cylce){cout<<"YES\n";}
	else{cout<<"NO\n";}

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


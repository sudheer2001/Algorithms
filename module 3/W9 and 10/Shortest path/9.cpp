#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<vector<int>>v;
vector<bool>visited;
vector<int>parlen;
int ans=1e6;
void dfs(int node, int par){
	par[node]=par;
	visited[node]=true;
	for(auto child:v[node]){
		if(!visited[child]){
			dfs(child,node);
		}else{
			int len=1;int x=child
			while()
		}
	}
}


void solve(){
	int n,m;cin>>n>>m;
	v.resize(n+1);visited.assign(n+1,false);parlen.assign(n+1,0);
	for (int i = 0; i < m; ++i)
		{
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}	
	for (int i = 1; i < n+1; ++i)
	{
		if(!visited[i]){
			dfs(i,0);
		}
	}
	if(ans!=1e5){cout<<ans<<endl;}else{cout<<-1<<endl;}

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


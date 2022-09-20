#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

const int N=20020;

vector<int>v[N];
int subtree[N];
// int parent[N];

void dfs(int node,int par){
	subtree[node]=1;
	// parent[node]=par;
	for(auto child:v[node]){
		if(child!=par){
			dfs(child,node);
			subtree[node]+=subtree[child];
		}
	}
}

void solve(){
	int n;cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	ll sum=0;
	for (int i = 1; i <= n; ++i)
	{
		sum+=subtree[i]*(n-subtree[i]);
	}
	cout<<sum<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


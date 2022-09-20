#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int n;

vector<vector<int>>v;
vector<int>subtree;
// int parent[N];

bool check(int node,int par){
	for(auto child:v[node]){
		if(child!=par){
			if(subtree[child]>n/2){

				return false;
			}
		}
	}
	return true;
}

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
	cin>>n;
	v.resize(n+1);subtree.assign(n+1,0);
	for (int i = 0; i < n-1; ++i)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	int node=1,par=0;
	while(!check(node,par)){
		par=node;
		node=*max_element(v[node].begin(), v[node].end());
	}
	cout<<node<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


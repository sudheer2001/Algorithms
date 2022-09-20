#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<vector<int>>v;
vector<int>col;
vector<int>parent;
// vector<int>cycle;
int odd_cycle=0;

void dfs(int node,int par){
	col[node]=2;parent[node]=par;
	for(auto child:v[node]){
		if(child==par){continue;}
		if(col[child]==1){
			dfs(child,node);
		}
		else if(col[child]==2){
			int curr=node;
			// cout<<child<<";";
			int cyclelen=1;
			while(curr!=child){
				// cout<<curr<<"--";
				if(curr==0){break;}
				curr=parent[curr];
				cyclelen++;
			}
			if(cyclelen%2==1){odd_cycle=1;}
		}
	}
}


void solve(){
	int n,m;cin>>n>>m;
	v.resize(n+1);col.assign(n+1,1);parent.assign(n+1,0);
	for (int i = 0; i < m; ++i)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i < n+1; ++i)
	{
		if(col[i]==1){
			// cycle.clear();
			dfs(i,0);
		}
	}
	if(odd_cycle==1){cout<<"NO\n";}else{cout<<"YES\n";}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


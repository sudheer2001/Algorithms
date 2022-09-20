#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<vector<int>>v;
vector<int>col;
int is_cycle=0;

void dfs(int node){
	col[node]=2;
	for(auto child:v[node]){
		if(col[child]==1){dfs(child);}
		else if(col[child]==2){is_cycle=1;}
        // else if(col[child]==3){continue;}
	}
	col[node]=3;
}


void solve(){
	int n,m;cin>>n>>m;
	v.assign(n+1,vector<int>());col.assign(n+1,1);
	for (int i = 0; i < m; ++i)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		// v[y].push_back(x);
	}
	for (int i = 1; i < n+1; ++i)
	{
		if(col[i]==1){
			dfs(i);
		}
	}
	if(is_cycle){cout<<"Yes"<<endl;}
	else{cout<<"No"<<endl;}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _t;cin>>_t;while(_t--)
	solve();
}


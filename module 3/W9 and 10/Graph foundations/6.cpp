#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<vector<pair<int,int>>>v;
vector<int>dist;

void bfs(int node){
	dist[node]=0;
	queue<int>q;
	q.push(node);
	while(!q.empty()){
		int cur=q.front();
		int curdis=dist[cur];
		q.pop();
		for (auto child:v[cur])
		{
			if(dist[child.first]>curdis+child.second){
				dist[child.first]=curdis+child.second;
				q.push(child.first);
			}
		}
	}
}

void solve(){
	int n,m;cin>>n>>m;
	v.resize(n+1);dist.assign(n+1,1e9);
	int sn;cin>>sn;
	for (int i = 0; i < m; ++i)
	{
		int x,y,z;cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	bfs(sn);
	for (int i = 1; i < n+1; ++i)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


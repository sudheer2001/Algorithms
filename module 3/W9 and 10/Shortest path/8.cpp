#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

#define F first
#define S second
typedef pair<int,int> ii;

int mod=1e9+7;
vector<vector<ii>>graph;
vector<int>dist;
vector<int>visited;
vector<int>num;vector<int>minf;vector<int>maxf;

void bfs(int node){
	dist[node]=0;
	priority_queue<ii>q;
	q.push({0,node});
	num[node]=1;
	while(!q.empty()){
		ii x=q.top();q.pop();
		int curd=-x.F,u=x.S;
		if(visited[u])continue;
		visited[u]=true;
		for(auto neighbour:graph[u]){
			int v=neighbour.F,w=neighbour.S;
			if(dist[v]>curd+w){
				dist[v]=curd+w;
				q.push({-dist[v],v});
				num[v]=num[u];minf[v]=minf[u]+1;maxf[v]=maxf[u]+1;
			}
			else if(dist[v]==curd+w){
				num[v]=(num[v]+num[u])%mod;
				minf[v]=min(minf[v],minf[u]+1);
				maxf[v]=max(maxf[v],maxf[u]+1);
			}


		}

	}

}


void solve(){
	int n,m;cin>>n>>m;
	graph.resize(n+1);
	dist.assign(n+1,1e18);visited.assign(n+1,false);
	num.assign(n+1,0);minf.assign(n+1,0);maxf.assign(n+1,0);
	for (int i = 0; i < m; ++i)
	{
		int x,y,z;cin>>x>>y>>z;
		graph[x].push_back({y,z});
		// graph[y].push_back({x,z});
	}
	bfs(1);
	if(dist[n]!=1e18){
	cout<<dist[n]<<" "<<num[n]<<" "<<minf[n]<<" "<<maxf[n]<<endl;
	}else{cout<<-1<<endl;}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


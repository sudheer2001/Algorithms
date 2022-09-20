#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

#define F first
#define S second
typedef pair<int,int> ii;

vector<vector<ii>>graph;
vector<int>dist;
vector<bool>visited;

void bfs(int node){
	dist[node]=0;
	priority_queue<ii>q;
	q.push({0,node});
	while(!q.empty()){
		ii x=q.top();q.pop();
		int curd=-x.F;
		if(visited[x.S])continue;
		visited[x.S]=true;
		for(auto neighbour:graph[x.S]){
			if(dist[neighbour.F]>curd+neighbour.S){
				dist[neighbour.F]=curd+neighbour.S;
				q.push({-dist[neighbour.F],neighbour.F});
			}
		}

	}

}

void findmax(int node){
	bfs(node);
	int mm=-1;  
                                    
	for (int i = 1; i < graph.size() ; ++i)
	{
		
		for (int j = 0; j < graph[i].size(); ++j)
		{

			int x=graph[i][j].F;
			int edgelen=graph[i][j].S;int dis=abs(dist[x]-dist[i]);
			mm=max(mm,(dist[i]+dist[x]+edgelen)*5);

		}
		// cout<<dist[i]<<"--";
	}
		
	cout<<mm<<endl;
	// cout << std::setprecision(0) << std::fixed << 10*mm << '\n';
}


void solve(){
	int n,m;cin>>n>>m;
	graph.resize(n+1);
	dist.assign(n+1,1e18);visited.assign(n+1,false);
	for (int i = 0; i < m; ++i)
	{
		int x,y,z;cin>>x>>y>>z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	int a;cin>>a;
	findmax(a);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


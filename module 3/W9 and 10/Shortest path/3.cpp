#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int


#define F first 
#define S second 
#define MP make_pair 
typedef pair<int,int> ii;



vector<vector<ii>>v;
// vector<int>dist;
vector<int>visited;
int sum=0;
void bfs(int node){
	priority_queue<ii>pq;
	// dist[node]=0;
	pq.push(MP(0,node));

	while(!pq.empty()){
		ii x=pq.top();pq.pop();
		// int curd=dist[x.S];
		if(visited[x.S]==1)continue;
		visited[x.S]=1;
		sum+=-x.F;

		for(auto neigh:v[x.S]){
			pq.push(MP(-neigh.S,neigh.F));
			}
		}

	}





void solve(){

	int n,m;cin>>n>>m;
	v.resize(n+1);
	// dist.assign(n+1,1e18);
	visited.assign(n+1,0);

	for (int i = 0; i < m; ++i)
	{
		int x,y,z;cin>>x>>y>>z;
		v[x].push_back(MP(y,z));
		v[y].push_back(MP(x,z));
	}
	bfs(1);
	for (int i = 1; i <=n ; ++i)
	{
		if(visited[i]!=1){cout<<"IMPOSSIBLE\n";return;}
	}
	cout<<sum<<endl;
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


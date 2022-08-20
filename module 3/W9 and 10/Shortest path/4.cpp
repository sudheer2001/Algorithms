#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

void solve(){
	int n,m,q;cin>>n>>m>>q;
	int dist[n+1][n+1];
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			if(i!=j)dist[i][j]=1e18;
			else{dist[i][j]=0;}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int x,y,z;cin>>x>>y>>z;
		dist[x][y]=dist[y][x]=z;

	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <=n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	while(q--){
		int x,y;cin>>x>>y;
		if(dist[x][y]==1e18)cout<<-1<<endl;
		else{cout<<dist[x][y]<<endl;}
	}

	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}


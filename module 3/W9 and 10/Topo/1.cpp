#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n,m;
vector<vector<int>>v;
vector<int>indegree;
vector<int>topo;

void kahn(){
	priority_queue<int>q;
	for (int i = 1; i < n+1; ++i)
	{
		if(indegree[i]==0){q.push(-i);}
	}
	int label=1;
	while(!q.empty()){
		int cur=-q.top();
		topo[cur]=label++;
		q.pop();
		for(auto node:v[cur]){
			indegree[node]--;
			if(indegree[node]==0){q.push(-node);}
		}

	}

}


void solve(){
	cin>>n>>m;
	v.resize(n+1);
	indegree.assign(n+1,0);
	topo.resize(n+1);
	for (int i = 0; i < m; ++i)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		indegree[y]++;
	}
	kahn();

		for (int i = 1; i < n+1; ++i)
	{
		cout<<topo[i]<<" ";
	}

	



}


signed main(){
	ios_base:: sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// int _t;cin>>_t;while(_t--)
	solve();

}
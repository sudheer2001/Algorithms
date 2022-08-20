#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

vector<vector<int>>v;
vector<int>parent;
vector<int>depth;
vector<int>subtree;

void dfs(int node,int par,int dep){
	parent[node]=par;depth[node]=dep;
	for(auto child:v[node]){
		if(child!=par){
			dfs(child,node,dep+1);
		}
	}

}


void solve(){
	int n;cin>>n;
	if(n==1){cout<<n<<endl;return;}
	v.resize(n+1);depth.resize(n+1);parent.resize(n+1);
	for (int i = 0; i < n-1; ++i)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,1,0);
	int maxdp=-1,occ=-1;
	for (int i = 1; i <= n; ++i)
	{
		if(depth[i]>maxdp){maxdp=depth[i];occ=i;}
	}
	dfs(occ,occ,0);
	maxdp=-1;occ=-1;
	for (int i = 1; i <= n; ++i)
	{
		if(depth[i]>maxdp){maxdp=depth[i];occ=i;}
	}
	// if diameter is odd, 2centers exist-----------------------------------------------------
	if(maxdp%2==1){
		maxdp/=2;int D=maxdp;
		// int left,right are the two centres
		while(maxdp){
			occ=parent[occ];
			maxdp--;
		}
		int right=occ,left=parent[occ];
		// cout<<left<<"--"<<right<<endl;
		int sum=0;int ans=0;int lcount=0,rcount=0;
		depth.assign(n+1,0);
		dfs(left,right,0);
		// cout<<D<<endl;
		for (int i = 1; i < n+1; ++i)
		{
			if(depth[i]==D){lcount++;}
		}
		depth.assign(n+1,0);
		dfs(right,left,0);
		for (int i = 0; i < n+1; ++i)
		{
			if(depth[i]==D){rcount++;}
		}
		// cout<<lcount<<"--"<<rcount<<endl;
		ans=lcount*rcount;
		cout<<ans<<endl;

	//----------------------------1 center----------------------------------------------------
	}
	else{
		maxdp/=2;
		int D=maxdp-1;
		while(maxdp){
			occ=parent[occ];
			maxdp--;
		}
		int sum=0;int ans=0;
		// cout<<D<<endl;
		for (auto child:v[occ]){
			depth.assign(n+1,0);
			dfs(child,occ,0);
			int l=0;
			for (int i = 1; i <depth.size() ; ++i)
			{
				if(depth[i]==D){l++;}
			}
			// cout<<l<<"--";
			ans-=l*l;
			sum+=l;
		}
		cout<<(ans+(sum*sum))/2<<endl;
	}

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}
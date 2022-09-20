#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define pr pair<int,int>
#define vt vector<int>
#define mii map<int,int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int> >
#define mod 1000000007
#define inf 1e18
#define w(x) int x; cin>>x; while(x--)


int D;
int cnt = 0;
int dis = 0;
vector<int> g[200010];
int par[200010];
int dep[200010];
void dfs(int node, int parent, int depth) {
	dep[node] = depth;
	par[node] = parent;
	if (depth == dis) {cnt++;}
	for (auto v : g[node]) {
		if (v != parent) {
			dfs(v, node, depth + 1);
		}
	}
}

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	if (n == 1) {
		cout << 1 << "\n";
		return;
	}
	dfs(1, 0, 0);
	D = 0;
	int maxch = 1;
	for (int i = 1; i <= n ; ++i)
	{
		if (dep[i] > D) {
			D = dep[i];
			maxch = i;
		}
	}
	dfs(maxch, 0, 0);
	D = 0;
	int maxch2 = maxch;
	for (int i = 1; i <= n ; ++i)
	{
		if (dep[i] > D) {
			D = dep[i];
			maxch2 = i;
		}
	}
	if (D % 2 == 0) {
		int a = D / 2;
		for (int i = 0; i < a; ++i)
		{
			maxch2 = par[maxch2];
		}
		vector<int> l;
		dis = a - 1;
		int total = 0;
		for (auto v : g[maxch2]) {
			cnt = 0;
			dfs(v, maxch2, 0);
			total += cnt;
			l.push_back(cnt);
		}
		int sum = 0;
		for (auto k : l) {
			sum += (total - k) * k;
		}
		cout << (sum / 2) << "\n";
	}
	else {
		int a = D / 2;
		for (int i = 0; i < a; ++i)
		{
			maxch2 = par[maxch2];
		}
		int maxch1 = par[maxch2];
		cnt = 0; dis = a;
		dfs(maxch1, maxch2, 0);
		int z = cnt;
		cnt = 0;
		dfs(maxch2, maxch1, 0);
		z *= cnt;
		cout << z << "\n";

	}

}


signed main()
{
	solve();
	return 0;
}
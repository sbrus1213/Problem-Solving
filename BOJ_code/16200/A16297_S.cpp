// BOJ 16297 Eating Everything Efficiently
// graph dp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<double> enj, dp;
vector<bool> vis;
vector<vector<int> > adj;

double dfs(int cur) {
	if (vis[cur]) return dp[cur];
	double mx = 0;
	vis[cur] = true;
	for (int nxt : adj[cur])
		mx = max(mx, dfs(nxt));
	return dp[cur] = max(mx, mx / 2 + enj[cur]);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	enj = vector<double>(n);
	for (int i = 0; i < n; ++i) cin >> enj[i];

	adj = vector<vector<int> >(n);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	vis = vector<bool>(n);
	dp = vector<double>(n);
	dfs(0);

	cout << fixed;
	cout.precision(6);
	cout << dp[0];
}
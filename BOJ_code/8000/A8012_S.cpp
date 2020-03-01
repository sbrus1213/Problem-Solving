// BOJ 8012 한동이는 영업사원!
// LCA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MXV = 30001;
const int psz = 15;

vector<vector<int> > adj(MXV), par(MXV, vector<int>(psz + 1)), dist(MXV, vector<int>(psz + 1));
vector<int> lev(MXV);

void dfs(int cur, int prev = 0) {
	lev[cur] = lev[prev] + 1;
	par[cur][0] = prev;
	dist[cur][0] = 1;
	for (int& next : adj[cur])
		if (!lev[next])
			dfs(next, cur);
}
void mktable(int n) {
	for (int j = 1; j <= psz; ++j)
		for (int i = 1; i <= n; ++i)
			par[i][j] = par[par[i][j - 1]][j - 1],
			dist[i][j] = dist[par[i][j - 1]][j - 1] + dist[i][j - 1];
}
int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);

	int diff = lev[u] - lev[v], x = 0, ret = 0;
	while (diff) {
		if (diff % 2) {
			ret += dist[u][x];
			u = par[u][x];
		}
		x++; diff >>= 1;
	}

	if (u == v) return ret;

	for (int i = psz; i >= 0; --i)
		if (par[u][i] != par[v][i]) {
			ret += dist[u][i] + dist[v][i];
			u = par[u][i], v = par[v][i];
		}
	ret += dist[u][0] + dist[v][0];
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	mktable(n);

	int m;
	cin >> m;

	int s = 1, ans = 0;
	for (int i = 0; i < m; ++i) {
		int e;
		cin >> e;
		ans += lca(s, e);
		s = e;
	}
	cout << ans;
}
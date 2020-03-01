// 3584 가장 가까운 공통 조상
// LCA

#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, int pre, vector<int>& level, vector<vector<int> >& adj) {
	if (!level[cur]) level[cur] = level[pre] + 1;
	for (int next : adj[cur])
		dfs(next, cur, level, adj);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		int par[10010][15] = {};
		vector<vector<int> > adj(10010);
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			par[v][0] = u;
		}

		int rt;
		for (int i = 1; i <= n; ++i)
			if (!par[i][0])
				rt = i;

		for (int j = 1; j < 15; ++j)
			for (int i = 1; i <= n; ++i)
				par[i][j] = par[par[i][j - 1]][j - 1];

		vector<int> lev(10010);
		lev[rt] = 1;
		dfs(rt, -1, lev, adj);

		int u, v, diff, id = 0;
		cin >> u >> v;
		if (lev[u] < lev[v]) swap(u, v);

		diff = lev[u] - lev[v];
		while (diff) {
			if (diff % 2) u = par[u][id];
			diff >>= 1;
			id++;
		}

		if (u == v) cout << u << '\n';
		else {
			for (int i = 14; i >= 0; --i) {
				if (par[u][i] == par[v][i]) continue;
				u = par[u][i]; v = par[v][i];
			}
			u = par[u][0]; v = par[v][0];
			cout << u << '\n';
		}
	}
}
// BOJ 11438 LCA 2
// LCA & Sparse table

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj(100001);
int par[100001][20], lev[100001];

void get_par(int cur, int prev = 0) {
	lev[cur] = lev[prev] + 1;
	par[cur][0] = prev;
	for (int next : adj[cur])
		if (next != prev)
			get_par(next, cur);
}
void make_table(int n) {
	for (int j = 1; j < 20; ++j)
		for (int i = 1; i <= n; ++i)
			par[i][j] = par[par[i][j - 1]][j - 1];
}
int lca_query(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);

	int diff = lev[u] - lev[v], x = 0;
	while (diff) {
		if (diff % 2) u = par[u][x];
		diff >>= 1;
		x++;
	}

	if (u == v) return u;
	else {
		for (int i = 19; i >= 0; --i)
			if (par[u][i] != par[v][i])
				u = par[u][i], v = par[v][i];
		return par[u][0];
	}
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

	get_par(1);
	make_table(n);

	int m;
	cin >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		cout << lca_query(u, v) << '\n';
	}
}
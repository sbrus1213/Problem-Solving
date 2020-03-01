// BOJ 1761 정점들의 거리
// LCA & Sparse table

#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector<vector<pii > > adj(40001);
pii par[40001][17];
int lev[40001];

void get_par(int cur, int prev = 0, int dist = 0) {
	lev[cur] = lev[prev] + 1;
	par[cur][0] = { prev, dist };
	for (auto& next : adj[cur])
		if (next.first != prev)
			get_par(next.first, cur, next.second);
}
void make_table(int n) {
	for (int j = 1; j < 17; ++j)
		for (int i = 1; i <= n; ++i) {
			par[i][j].first = par[par[i][j - 1].first][j - 1].first;
			par[i][j].second = par[par[i][j - 1].first][j - 1].second + par[i][j - 1].second;
		}
}
int query(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);

	int diff = lev[u] - lev[v], x = 0, dist = 0;
	while (diff) {
		if (diff % 2) {
			dist += par[u][x].second;
			u = par[u][x].first;
		}
		diff >>= 1;
		x++;
	}

	if (u == v) return dist;
	else {
		for (int i = 16; i >= 0; --i) {
			if (par[u][i].first == par[v][i].first) continue;
			dist += par[u][i].second + par[v][i].second;
			u = par[u][i].first, v = par[v][i].first;
		}
		dist += par[u][0].second + par[v][0].second;
		return dist;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	get_par(1);
	make_table(n);

	int m;
	cin >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		cout << query(u, v) << '\n';
	}
}
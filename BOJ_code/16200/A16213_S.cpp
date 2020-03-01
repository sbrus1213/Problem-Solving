// BOJ 16213 dgeu-learning
// MST & LCA 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MXV = 200001;
const int INF = 1e9 + 7;
const int psz = 18;

struct edge {
	int s, e, w;
};

vector<vector<pii > > adj(MXV), par(MXV, vector<pii >(psz + 1));
vector<int> uf(MXV), lev(MXV);

int find(int x) {
	if (uf[x] == -1) return x;
	return uf[x] = find(uf[x]);
}
bool merge(edge& e) {
	int ps = find(e.s), pe = find(e.e);
	if (ps == pe) return false;
	uf[ps] = pe;
	return true;
}
void dfs(int cur, int prev = 0, int dist = 0) {
	lev[cur] = lev[prev] + 1;
	fill(par[cur].begin(), par[cur].end(), pii(0, INF));
	par[cur][0] = { prev, dist };
	for (auto& next : adj[cur])
		if (!lev[next.first])
			dfs(next.first, cur, next.second);
}
void mktable(int n) {
	for (int j = 1; j <= psz; ++j) {
		for (int i = 1; i <= n; ++i) {
			par[i][j].first = par[par[i][j - 1].first][j - 1].first;
			par[i][j].second = min(par[par[i][j - 1].first][j - 1].second, par[i][j - 1].second);
		}
	}
}
int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);

	int diff = lev[u] - lev[v], x = 0;
	int ret = INF;
	while (diff) {
		if (diff % 2) {
			ret = min(ret, par[u][x].second);
			u = par[u][x].first;
		}
		diff >>= 1; x++;
	}

	if (u == v) return ret;

	for (int i = psz; i >= 0; --i) {
		if (par[u][i].first == par[v][i].first) continue;
		ret = min(ret, par[u][i].second);
		ret = min(ret, par[v][i].second);
		u = par[u][i].first; v = par[v][i].first;
	}
	ret = min(ret, par[u][0].second);
	ret = min(ret, par[v][0].second);

	return  ret;
}


int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;

	vector<edge> E;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({ u, v, w });
	}

	sort(E.begin(), E.end(), [](edge& a, edge& b) {
		return a.w > b.w;
		});

	fill(uf.begin(), uf.end(), -1);
	for (auto& cur : E) {
		if (merge(cur)) {
			adj[cur.s].push_back(pii(cur.e, cur.w));
			adj[cur.e].push_back(pii(cur.s, cur.w));
		}
	}

	dfs(1);
	mktable(n);

	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}
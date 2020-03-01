// BOJ 15481 그래프와 MST
// MST & LCA 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MXV = 200001;
const int psz = 18;

struct edge {
	int s, e, idx, w;
	ll sz;
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
void dfs(int cur, int prev = 0, ll dist = 0) {
	lev[cur] = lev[prev] + 1;
	par[cur][0] = { prev, dist };
	for (auto& next : adj[cur])
		if (!lev[next.first])
			dfs(next.first, cur, next.second);
}
void mktable(int n) {
	for (int j = 1; j <= psz; ++j) {
		for (int i = 1; i <= n; ++i) {
			par[i][j].first = par[par[i][j - 1].first][j - 1].first;
			par[i][j].second = max(par[par[i][j - 1].first][j - 1].second, par[i][j - 1].second);
		}
	}
}
pii lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);

	int diff = lev[u] - lev[v], x = 0;
	int ret = -1;
	while (diff) {
		if (diff % 2) {
			ret = max(ret, par[u][x].second);
			u = par[u][x].first;
		}
		diff >>= 1; x++;
	}

	if (u == v) return pii(u, ret);

	for (int i = psz; i >= 0; --i) {
		if (par[u][i].first == par[v][i].first) continue;
		ret = max(ret, par[u][i].second);
		ret = max(ret, par[v][i].second);
		u = par[u][i].first; v = par[v][i].first;
	}
	ret = max(ret, par[u][0].second);
	ret = max(ret, par[v][0].second);

	return pii(par[u][0].first, ret);
}


int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<edge> E;
	for (int i = 0; i < m; ++i) {
		int u, v; ll w;
		cin >> u >> v >> w;
		E.push_back({ u, v, i, w, 0 });
	}

	sort(E.begin(), E.end(), [](edge& a, edge& b) {
		return a.w < b.w;
		});

	int cnt = 1;
	ll mst = 0;
	fill(uf.begin(), uf.end(), -1);
	for (auto& cur : E) {
		if (merge(cur)) {
			cnt++;
			mst += cur.w;
			adj[cur.s].push_back(pii(cur.e, cur.w));
			adj[cur.e].push_back(pii(cur.s, cur.w));
			cur.sz = 1;
		}
	}

	dfs(1);
	mktable(n);

	ll ans;
	for (auto& cur : E) {
		if (cur.sz) cur.sz = mst;
		else {
			pii res = lca(cur.s, cur.e);
			ans = cur.w - res.second;
			cur.sz = mst + ans;
		}
	}

	sort(E.begin(), E.end(), [](edge& a, edge& b) {
		return a.idx < b.idx;
		});

	for (auto& cur : E) cout << cur.sz << '\n';
}
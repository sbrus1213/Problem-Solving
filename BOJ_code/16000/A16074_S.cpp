// BOJ 16074 Mountaineers
// MST & LCA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct edge {
	int u, v, w;
};

vector<int> par;

int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

struct lca {
	int n;
	const int mxn = 250001, psz = 16;
	vector<vector<int> > par, dist;
	vector<vector<pii> > adj;
	vector<int> lev;
	lca(int n_) : n(n_) {
		par = vector<vector<int> >(mxn, vector<int>(psz + 1));
		dist = vector<vector<int> >(mxn, vector<int>(psz + 1));
		adj = vector<vector<pii> >(mxn);
		lev = vector<int>(mxn);
	}
	void dfs(int cur, int prev = 0, int d = 0) {
		lev[cur] = lev[prev] + 1;
		par[cur][0] = prev;
		dist[cur][0] = d;
		for (auto& next : adj[cur])
			if (!lev[next.first])
				dfs(next.first, cur, next.second);
	}
	void mktable() {
		for (int j = 1; j <= psz; ++j)
			for (int i = 1; i <= n; ++i) {
				par[i][j] = par[par[i][j - 1]][j - 1];
				dist[i][j] = max(dist[par[i][j - 1]][j - 1], dist[i][j - 1]);
			}
	}
	int query(int u, int v) {
		if (lev[u] < lev[v]) swap(u, v);

		int diff = lev[u] - lev[v], x = 0, ans = 0;
		while (diff) {
			if (diff % 2) {
				ans = max(ans, dist[u][x]);
				u = par[u][x];
			}
			diff >>= 1; x++;
		}
		if (u == v) return ans;

		for (int i = psz; i >= 0; --i)
			if (par[u][i] != par[v][i]) {
				ans = max(ans, max(dist[u][i], dist[v][i]));
				u = par[u][i], v = par[v][i];
			}
		ans = max(ans, max(dist[u][0], dist[v][0]));
		return ans;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, q; cin >> n >> m >> q;

	vector<int> mtn(n * m + 1);
	for (int i = 1; i <= n * m; ++i) cin >> mtn[i];

	int di[] = { 1, 0 }, dj[] = { 0, 1 };
	vector<edge> E;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int id = i * m + j + 1;
			for (int k = 0; k < 2; ++k) {
				int ni = i + di[k], nj = j + dj[k];
				if (ni < 0 || ni >= n) continue;
				if (nj < 0 || nj >= m) continue;
				int idx = ni * m + nj + 1;
				E.push_back({ id, idx, max(mtn[id], mtn[idx]) });
			}
		}
	}

	sort(E.begin(), E.end(), [&](edge a, edge b) {
		return a.w < b.w;
		});

	par = vector<int>(n * m + 1, -1);
	lca L(n * m + 1);
	for (auto e : E)
		if (merge(e.u, e.v)) {
			L.adj[e.u].push_back({ e.v, e.w });
			L.adj[e.v].push_back({ e.u, e.w });
		}
	L.dfs(1);
	L.mktable();

	for (int i = 0; i < q; ++i) {
		int fx, fy, tx, ty; cin >> fx >> fy >> tx >> ty;
		fx--; fy--; tx--; ty--;
		int f = fx * m + fy + 1, t = tx * m + ty + 1;
		if (f == t) cout << mtn[f] << '\n';
		else cout << L.query(f, t) << '\n';
	}
}
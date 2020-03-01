// BOJ 13511 Æ®¸®¿Í Äõ¸® 2
// LCA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int MXV = 100001;
const int psz = 18;

vector<vector<pll > > adj(MXV), par(MXV, vector<pll >(psz + 1));
vector<int> vis(MXV), lev(MXV);
int n;

void dfs(int cur, int prev = 0, ll dist = 0) {
	lev[cur] = lev[prev] + 1;
	vis[cur] = 1;
	par[cur][0] = { prev, dist };
	for (auto& next : adj[cur])
		if (!vis[next.first])
			dfs(next.first, cur, next.second);
}
void mktable() {
	for (int i = 1; i < psz; ++i)
		for (int j = 1; j <= n; ++j) {
			par[j][i].first = par[par[j][i - 1].first][i - 1].first;
			par[j][i].second = par[par[j][i - 1].first][i - 1].second + par[j][i - 1].second;
		}
}
pll lca_query(int u, int v) {
	int diff, x = 0;
	ll ret = 0;

	if (lev[u] < lev[v]) swap(u, v);
	diff = lev[u] - lev[v];
	while (diff) {
		if (diff % 2) {
			ret += par[u][x].second;
			u = par[u][x].first;
		}
		diff >>= 1;
		x++;
	}
	if (u == v) return pll(ret, u);
	for (int i = psz - 1; i >= 0; --i) {
		if (par[u][i].first == par[v][i].first) continue;
		ret += par[u][i].second + par[v][i].second;
		u = par[u][i].first; v = par[v][i].first;
	}
	ret += par[u][0].second + par[v][0].second;
	u = v = par[u][0].first;
	return pll(ret, u);
}
int kth_query(int u, int v, int k) {
	pll lca = lca_query(u, v);
	int x = 0;
	--k;
	if (lev[u] - lev[lca.second] >= k) {
		while (k) {
			if (k % 2) u = par[u][x].first;
			k >>= 1; x++;
		}
		return u;
	}
	else {
		k = (lev[v] - lev[lca.second]) - (k - lev[u] + lev[lca.second]);
		while (k) {
			if (k % 2) v = par[v][x].first;
			k >>= 1; x++;
		}
		return v;
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i < n; ++i) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	dfs(1);
	mktable();

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int comm, u, v, k;
		cin >> comm >> u >> v;
		if (comm == 1) 
			cout << lca_query(u, v).first << '\n';
		else {
			cin >> k;
			cout << kth_query(u, v, k) << '\n';
		}
	}
}
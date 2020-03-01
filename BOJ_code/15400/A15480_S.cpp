// BOJ 15480 LCA¿Í Äõ¸®
// LCA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxn = 100001;
const int psz = 16;

vector<vector<int> > adj(mxn), par(mxn, vector<int>(psz + 1));
vector<int> lev(mxn);

inline int max3(int a, int b, int c) {
	return max(a, max(b, c));
}
void dfs(int cur, int pre = 0) {
	par[cur][0] = pre;
	lev[cur] = lev[pre] + 1;
	for (int& next : adj[cur])
		if (!lev[next]) dfs(next, cur);
}
void mktable(int n) {
	for (int i = 1; i <= psz; ++i)
		for (int j = 1; j <= n; ++j)
			par[j][i] = par[par[j][i - 1]][i - 1];
}
int lca(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);
	int diff = lev[u] - lev[v], x = 0;
	while (diff) {
		if (diff % 2) u = par[u][x];
		x++; diff >>= 1;
	}
	if (u == v) return u;
	for (int i = psz; i >= 0; --i) 
		if (par[u][i] != par[v][i]) 
			u = par[u][i], v = par[v][i];
	return par[u][0];
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

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int r, u, v; cin >> r >> u >> v;
		int ru = lca(r, u), rv = lca(r, v), uv = lca(u, v);

		if (ru == r && rv == r) cout << uv << '\n';
		else if (ru == r || rv == r) cout << r << '\n';
		else if (ru == u && rv == v) cout << (lev[u] > lev[v] ? u : v) << '\n';
		else {
			int mxlev = max3(lev[ru], lev[rv], lev[uv]);
			if (lev[ru] == mxlev) cout << ru << '\n';
			else if (lev[rv] == mxlev) cout << rv << '\n';
			else cout << uv << '\n';
		}
	}

}
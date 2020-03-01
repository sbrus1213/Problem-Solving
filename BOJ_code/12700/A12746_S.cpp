// BOJ 12746 Traffic (Large)
// LCA 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MXV = 222223;
const int psz = 17;

vector<vector<int> > adj(MXV), par(MXV, vector<int>(psz + 1)), cnt(MXV, vector<int>(psz + 1));
vector<int> lev(MXV), res(MXV);

void dfs(int cur, int prev = 0) {
	lev[cur] = lev[prev] + 1;
	par[cur][0] = prev;
	for (int next : adj[cur])
		if (!lev[next])
			dfs(next, cur);
}
void mktable(int n) {
	for (int j = 1; j <= psz; ++j)
		for (int i = 1; i <= n; ++i)
			par[i][j] = par[par[i][j - 1]][j - 1];
}
void update(int u, int v) {
	if (lev[u] < lev[v]) swap(u, v);

	int diff = lev[u] - lev[v], x = 0;
	while (diff) {
		if (diff % 2) {
			cnt[u][x]++;
			u = par[u][x];
		}
		diff >>= 1; x++;
	}

	if (u == v) return;

	for (int i = psz; i >= 0; --i) {
		if (par[u][i] == par[v][i]) continue;
		cnt[u][i]++; cnt[v][i]++;
		u = par[u][i]; v = par[v][i];
	}
	cnt[u][0]++; cnt[v][0]++;
	return;
}
void query(int cur) {
	for (int next : adj[cur])
		if (lev[cur] < lev[next])
			query(next);
	int tmp = 0;
	for (int i = psz; i > 0; --i) {
		tmp += cnt[cur][i];
		cnt[par[cur][i - 1]][i - 1] += tmp;
	}
	res[cur] = tmp + cnt[cur][0];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	mktable(n);

	for (int i = 0; i < q; ++i) {
		int u, v; cin >> u >> v;
		update(u, v);
	}

	query(1);

	int mx = -1;
	vector<pii > ans;
	for (int i = 1; i <= n; ++i) {
		if (mx < res[i]) {
			mx = res[i];
			ans.clear();
			ans.push_back({ i, par[i][0] });
			ans.push_back({ par[i][0], i });
		}
		else if (mx == cnt[i][0]) {
			ans.push_back({ i, par[i][0] });
			ans.push_back({ par[i][0], i });
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0].first << ' ' << ans[0].second << ' ' << mx;
}
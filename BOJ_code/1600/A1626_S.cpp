// BOJ 1626 두 번째로 작은 스패닝 트리
// MST & LCA 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using pii = pair<int, int>;
const int INF = INT_MAX;
const int MXV = 50001;
const int psz = 16;

struct edge {
	int s, e, w;
	bool used;
};

vector<vector<pii > > adj(MXV);
vector<vector<int> > par(MXV, vector<int >(psz + 1)), mx(MXV, vector<int >(psz + 1)), mx2(MXV, vector<int >(psz + 1));
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
	par[cur][0] = prev;
	fill(mx[cur].begin(), mx[cur].end(), -1);
	mx[cur][0] = dist;
	fill(mx2[cur].begin(), mx2[cur].end(), -1);
	for (auto& next : adj[cur])
		if (!lev[next.first])
			dfs(next.first, cur, next.second);
}
void mktable(int n) {
	for (int j = 1; j <= psz; ++j) {
		for (int i = 1; i <= n; ++i) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			int tmp[4] = { mx[par[i][j - 1]][j - 1], mx[i][j - 1], mx2[par[i][j - 1]][j - 1], mx2[i][j - 1] };
			sort(tmp, tmp + 4);
			mx[i][j] = tmp[3];
			for (int k = 2; k >= 0; --k)
				if (tmp[k] != tmp[3]) {
					mx2[i][j] = tmp[k];
					break;
				}
		}
	}
}
int lca(int u, int v, int w) {
	vector<int> candi = { -1,-1 };

	if (lev[u] < lev[v]) swap(u, v);

	int diff = lev[u] - lev[v], x = 0;
	while (diff) {
		if (diff % 2) {
			if (mx[u][x] < w) candi.push_back(mx[u][x]);
			if (mx2[u][x] < w) candi.push_back(mx2[u][x]);
			u = par[u][x];
		}
		diff >>= 1; x++;
	}

	sort(candi.begin(), candi.end());
	if (u == v) return candi[candi.size() - 1];

	for (int i = psz; i >= 0; --i) {
		if (par[u][i] == par[v][i]) continue;
		if (mx[u][i] < w) candi.push_back(mx[u][i]);
		if (mx[v][i] < w) candi.push_back(mx[v][i]);
		if (mx2[u][i] < w)candi.push_back(mx2[u][i]);
		if (mx2[v][i] < w)candi.push_back(mx2[v][i]);
		u = par[u][i]; v = par[v][i];
	}
	if (mx[u][0] < w)candi.push_back(mx[u][0]);
	if (mx[v][0] < w)candi.push_back(mx[v][0]);
	if (mx2[u][0] < w)candi.push_back(mx2[u][0]);
	if (mx2[v][0] < w)candi.push_back(mx2[v][0]);

	sort(candi.begin(), candi.end());
	return candi[candi.size() - 1];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<edge> E;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({ u, v, w, false });
	}

	sort(E.begin(), E.end(), [](edge& a, edge& b) {
		return a.w < b.w;
		});

	int cnt = 1, mst = 0;
	fill(uf.begin(), uf.end(), -1);
	for (auto& cur : E) {
		if (merge(cur)) {
			cnt++;
			mst += cur.w;
			cur.used = true;
			adj[cur.s].push_back(pii(cur.e, cur.w));
			adj[cur.e].push_back(pii(cur.s, cur.w));
		}
	}

	if (cnt != n) {
		cout << -1;
		return 0;
	}

	dfs(1);
	mktable(n);

	int ans = INF;
	for (auto& cur : E) {
		if (cur.used) continue;
		int res = lca(cur.s, cur.e, cur.w);
		if (res != -1) ans = min(ans, cur.w - res);
	}
	if (ans == INF) cout << -1;
	else cout << mst + ans;
}
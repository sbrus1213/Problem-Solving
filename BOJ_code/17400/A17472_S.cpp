// BOJ 17472 다리 만들기 2
// dfs bfs & union find & mst

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct edge {
	int u, v, w;
};

int n, m, mp[11][11];
int vis[11][11], vc;
int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
int par[10];

bool isout(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m) return true;
	return false;
}
void dfs(int i, int j) {
	vis[i][j] = vc;
	for (int k = 0; k < 4; ++k) {
		int ni = i + di[k], nj = j + dj[k];
		if (isout(ni, nj)) continue;
		if (vis[ni][nj]) continue;
		if (mp[i][j] != mp[ni][nj]) continue;
		dfs(ni, nj);
	}
}
int find(int i) {
	if (par[i] < 0) return i;
	return par[i] = find(par[i]);
}
bool merge(int i, int j) {
	i = find(i), j = find(j);
	if (i == j) return false;
	par[i] = j;
	return true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mp[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] && !vis[i][j]) {
				++vc;
				dfs(i, j);
			}
		}
	}

	vector<edge> E;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j]) continue;
			for (int k = 0; k < 2; ++k) {
				int l, ni = i, nj = j;
				for (l = 0;; ++l) {
					ni += di[k];
					nj += dj[k];
					if (isout(ni, nj)) break;
					if (vis[ni][nj] == vis[i][j]) break;
					if (vis[ni][nj]) break;
				}
				if (isout(ni, nj)) continue;
				if (vis[ni][nj] == vis[i][j]) continue;
				if (l < 2) continue;
				E.push_back({ vis[i][j], vis[ni][nj], l });
			}
		}
	}

	sort(E.begin(), E.end(), [&](edge a, edge b) {
		return a.w < b.w;
		});

	int ans = 0, cnt = 0;
	fill(par, par + 10, -1);
	for (edge& e : E) {
		if (merge(e.u, e.v)) {
			ans += e.w;
			cnt++;
		}
	}

	if (cnt == vc - 1) cout << ans;
	else cout << -1;
}
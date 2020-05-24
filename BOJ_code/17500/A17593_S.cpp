// BOJ 17593 Slow leak
// floyd warshall

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll inf = 1e16;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	ll n, m, t, d; cin >> n >> m >> t >> d;

	vector<int> charge = { 1 };
	for (int i = 0; i < t; ++i) {
		int x; cin >> x;
		charge.push_back(x);
	}
	charge.push_back(n);

	ll dist[501][501];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dist[i][j] = inf;

	for (int i = 0; i < m; ++i) {
		ll u, v, w; cin >> u >> v >> w;
		if (w > d) continue;
		dist[u][v] = w;
		dist[v][u] = w;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	ll dist2[501][501];
	for (int i = 0; i <= t + 1; ++i)
		for (int j = 0; j <= t + 1; ++j)
			dist2[i][j] = inf;

	for (int i = 0; i <= t + 1; ++i) {
		for (int j = i + 1; j <= t + 1; ++j) {
			int ii = charge[i], jj = charge[j];
			if (dist[ii][jj] <= d) {
				dist2[i][j] = dist2[j][i] = dist[ii][jj];
			}
		}
	}

	for (int k = 0; k <= t + 1; ++k) {
		for (int i = 0; i <= t + 1; ++i) {
			for (int j = 0; j <= t + 1; ++j) {
				dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
			}
		}
	}

	if (dist2[0][t + 1] == inf) cout << "stuck";
	else cout << dist2[0][t + 1];
}
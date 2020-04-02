// BOJ 13907 ¼¼±Ý
// Bellman ford

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;

struct edge {
	int u, v, w;
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, s, e; cin >> n >> m >> k >> s >> e;

	vector<edge> E;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		E.push_back({ u, v, w });
	}

	int dist[1001][1001];
	for (int i = 0; i < n; ++i) for (int j = 1; j <= n; ++j) dist[i][j] = inf;
	dist[0][s] = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dist[i][E[j].u] = min(dist[i][E[j].u], dist[i - 1][E[j].v] + E[j].w);
			dist[i][E[j].v] = min(dist[i][E[j].v], dist[i - 1][E[j].u] + E[j].w);
		}
	}

	for (int i = 0; i <= k; ++i) {
		int mn = inf;
		for (int j = 0; j < n; ++j) mn = min(mn, dist[j][e]);
		cout << mn << '\n';

		if (i == k) break;
		int p; cin >> p;
		for (int j = 0; j < n; ++j) if (dist[j][e] < inf) dist[j][e] += j * p;
	}
}
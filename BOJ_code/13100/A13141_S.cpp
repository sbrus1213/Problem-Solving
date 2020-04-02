// BOJ 13141 Ignition
// floyd warshall

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

	int n, m; cin >> n >> m;

	vector<edge> E;
	int dist[201][201];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dist[i][j] = inf;
	for (int i = 1; i <= n; ++i) dist[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		E.push_back({ u, v, w });
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = inf;
	for (int i = 1; i <= n; ++i) {
		int tmp = 0;
		for (int j = 0; j < m; ++j)
			tmp = max(tmp, dist[i][E[j].u] + dist[i][E[j].v] + E[j].w);
		ans = min(ans, tmp);
	}
	cout << fixed;
	cout.precision(1);
	cout << (double)ans / 2;
}
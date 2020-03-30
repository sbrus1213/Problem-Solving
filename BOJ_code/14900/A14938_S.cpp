// BOJ 14938 서강그라운드
// floyd warshall

#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1e9;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r, t[101]; cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i) cin >> t[i];

	int dist[101][101];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dist[i][j] = inf;
	for (int i = 1; i <= n; ++i) dist[i][i] = 0;
	for (int i = 0; i < r; ++i) {
		int u, v, w; cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int s = 0;
		for (int j = 1; j <= n; ++j)
			if (dist[i][j] <= m) s += t[j];
		ans = max(ans, s);
	}
	cout << ans;
}
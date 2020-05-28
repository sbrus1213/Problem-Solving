// BOJ 10217 KCM Travel
// Floyd warshall

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int inf = 1e9;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n, m, k; cin >> n >> m >> k;

		vector<vector<int>> cost(n + 1, vector<int>(n + 1, inf));
		vector<vector<pii>> adj(n + 1);
		for (int i = 0; i < k; ++i) {
			int u, v, c, d; cin >> u >> v >> c >> d;
			if (c > m) continue;
			adj[u].push_back({ v, d });
			cost[u][v] = c;
		}

		for (int l = 1; l <= n; ++l)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

		if (cost[1][n] > m) {
			cout << "Poor KCM\n";
			continue;
		}

		vector<int> dist(n + 1, inf);

	}
}
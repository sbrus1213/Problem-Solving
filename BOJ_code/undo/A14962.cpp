// BOJ 14962 Vacation Plans
// shortest path

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int from, w;
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p; cin >> p;

	vector<vector<edge> > E[3];
	vector<long long> dist[3][2], h[3];
	int n[3], e[3], dest[3], mx = 0;
	for (int i = 0; i < p; ++i) {
		cin >> n[i] >> e[i];
		mx = max(mx, n[i] * e[i]);
		dist[i][0] = vector<long long>(n[i] + 1, 1e15);
		dist[i][1] = vector<long long>(n[i] + 1, 1e15);
		dist[i][1][1] = 0;
		E[i] = vector<vector<edge> >(n[i] + 1);
		h[i] = vector<long long>(n[i] + 1);
		for (int j = 1; j <= n[i]; ++j) cin >> h[i][j];
		for (int j = 0; j < e[i]; ++j) {
			int u, v, g; cin >> u >> v >> g;
			E[i][v].push_back({ u, g });
		}
		cin >> dest[i];
	}

	long long ans = 1e15;
	for (int i = 0; i < mx *5; ++i) {
		long long tmp = 0;
		for (int j = 0; j < p; ++j) {
			for (int k = 1; k <= n[j]; ++k) dist[j][i % 2][k] = dist[j][(i + 1) % 2][k] + h[j][k];
			for (int k = 1; k <= n[j]; ++k)
				for (auto& ee : E[j][k])
					dist[j][i % 2][k] = min(dist[j][i % 2][k], dist[j][(i + 1) % 2][ee.from] + ee.w);
			tmp += dist[j][i % 2][dest[j]];
		}
		ans = min(ans, tmp);
	}
	cout << ans;
}
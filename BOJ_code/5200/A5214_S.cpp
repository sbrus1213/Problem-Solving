// BOJ 5214 환승
// Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, k; cin >> n >> k >> m;

	vector<vector<int>> adj(n + 1 + m);
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < k; ++j) {
			int x; cin >> x;
			adj[n + i].push_back(x);
			adj[x].push_back(n + i);
		}
	}

	vector<int> dist(n + 1 + m, 2 * n);
	dist[1] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(dist[1], 1));
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		while (!pq.empty() && pq.top().second == cur.second) {
			pq.pop();
		}
		for (int nxt : adj[cur.second]) {
			if (dist[nxt] > dist[cur.second] + 1) {
				dist[nxt] = dist[cur.second] + 1;
				pq.push(pii(dist[nxt], nxt));
			}
		}
	}

	if (dist[n] == 2 * n) cout << -1;
	else cout << (dist[n] / 2) + 1;
}
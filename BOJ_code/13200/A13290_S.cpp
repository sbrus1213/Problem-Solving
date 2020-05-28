// BOJ 13290 Big Truck
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> item(n + 1);
	for (int i = 1; i <= n; ++i) cin >> item[i];

	int e; cin >> e;
	vector<vector<pii>> adj(n + 1);
	for (int i = 0; i < e; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	vector<int> dist(n + 1, 1e8), cnt(n+1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[1] = 0; cnt[1] = item[1];
	pq.push(pii(0, 1));
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		while (!pq.empty() && cur.second == pq.top().second) pq.pop();
		for (auto nxt : adj[cur.second]) {
			if (dist[nxt.first]>dist[cur.second] + nxt.second) {
				dist[nxt.first] = dist[cur.second] + nxt.second;
				cnt[nxt.first] = cnt[cur.second] + item[nxt.first];
				pq.push(pii(dist[nxt.first], nxt.first));
			}
			else if(dist[nxt.first] == dist[cur.second] + nxt.second) {
				if (cnt[nxt.first] < cnt[cur.second] + item[nxt.first]) {
					cnt[nxt.first] = cnt[cur.second] + item[nxt.first];
					pq.push(pii(dist[nxt.first], nxt.first));
				}
			}
		}
	}
	if (dist[n] == 1e8) cout << "impossible";
	else cout << dist[n] << ' ' << cnt[n];
}
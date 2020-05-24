// BOJ 15422 Bumped!
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
const ll inf = 1e17;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, f, s, e; cin >> n >> m >> f >> s >> e;

	vector<vector<pli>> adj1(n);
	vector<vector<int>> adj2(n);
	for (int i = 0; i < m; ++i) {
		int u, v; ll w; cin >> u >> v >> w;
		adj1[u].push_back({ w, v });
		adj1[v].push_back({ w, u });
	}
	for (int i = 0; i < f; ++i) {
		int u, v; cin >> u >> v;
		adj2[u].push_back(v);
	}

	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({ 0, s });
	vector<vector<ll>> dist(n, vector<ll>(2, inf));
	dist[s][0] = 0;
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		while (!pq.empty() && cur.second == pq.top().second) pq.pop();
		int u = cur.second % n, fl = cur.second / n;
		for (auto nxt : adj1[u]) {
			if (dist[nxt.second][fl] > dist[u][fl] + nxt.first) {
				dist[nxt.second][fl] = dist[u][fl] + nxt.first;
				pq.push(pli(dist[nxt.second][fl], nxt.second + fl * n));
			}
		}
		if (fl) continue;
		for (int nxt : adj2[u]) {
			if (dist[nxt][fl + 1] > dist[u][fl]) {
				dist[nxt][fl + 1] = dist[u][fl];
				pq.push(pli(dist[nxt][fl + 1], nxt + n));
			}
		}
	}
	cout << min(dist[e][0], dist[e][1]);
}
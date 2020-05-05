// BOJ 1238 파티
// dijkstra / bellman ford

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 1e9;
using pii = pair<int, int>;

void dijk(vector<vector<pii>>& adj, vector<int>& dist, int x) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, x });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		for (auto& nxt : adj[cur.second]) {
			if (dist[nxt.first] > dist[cur.second] + nxt.second) {
				dist[nxt.first] = dist[cur.second] + nxt.second;
				pq.push(pii(dist[nxt.first], nxt.first));
			}
		}
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, x; cin >> n >> m >> x;


	vector<vector<pii>> adj(n + 1), radj(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		radj[v].push_back({ u, w });
	}

	vector<int> come(n + 1, inf);
	come[x] = 0;
	dijk(adj, come, x);

	vector<int> go(n + 1, inf);
	go[x] = 0;
	dijk(radj, go, x);

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, go[i] + come[i]);
	cout << ans;
}

//struct Edge {
//	int u, v, w;
//};
//
//vector<Edge> edge;
//void bmf(vector<int>& vec) {
//	for (auto& e : edge)
//		if (vec[e.u] != inf && vec[e.v] > vec[e.u] + e.w)
//			vec[e.v] = vec[e.u] + e.w;
//}
//
//int main() {
//	cin.tie(NULL); ios_base::sync_with_stdio(false);
//
//	int n, m, x; cin >> n >> m >> x;
//
//	edge = vector<Edge>(m);
//	for (int i = 0; i < m; ++i)
//		cin >> edge[i].u >> edge[i].v >> edge[i].w;
//
//	vector<int> come(n + 1, inf);
//	come[x] = 0;
//	for (int i = 1; i < n; ++i) bmf(come);
//
//	for (auto& e : edge)
//		swap(e.u, e.v);
//
//	vector<int> go(n + 1, inf);
//	go[x] = 0;
//	for (int i = 1; i < n; ++i) bmf(go);
//
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//		ans = max(ans, go[i] + come[i]);
//	cout << ans;
//}
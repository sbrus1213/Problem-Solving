// BOJ 9370 미확인 도착지
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int inf = 2e8;

void dijkstra(vector<vector<pii>>& adj, vector<int>& dist, int st) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[st], st });
	while (!pq.empty()) {
		auto c = pq.top(); pq.pop();
		int cur = c.second;
		if (c.first > dist[cur]) continue;
		for (auto nxt : adj[cur]) {
			if (dist[nxt.first] > dist[cur] + nxt.second) {
				dist[nxt.first] = dist[cur] + nxt.second;
				pq.push(pii(dist[nxt.first], nxt.first));
			}
		}
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n, m, t; cin >> n >> m >> t;
		int s, g, h; cin >> s >> g >> h;

		vector<vector<pii>> adj(n + 1);
		for (int i = 0; i < m; ++i) {
			int u, v, w; cin >> u >> v >> w;
			adj[u].push_back({ v, w });
			adj[v].push_back({ u, w });
		}

		vector<int> dist1(n + 1, inf);
		dist1[s] = 0;
		dijkstra(adj, dist1, s);

		vector<int> dist2(n + 1, inf);
		int st;
		if (dist1[g] > dist1[h]) {
			st = g;
			dist2[st] = dist1[st];
		}
		else {
			st = h;
			dist2[st] = dist1[st];
		}
		dijkstra(adj, dist2, st);

		vector<int> ends(t), ans;
		for (int& x : ends) {
			cin >> x;
			if (dist1[x] == dist2[x] && dist1[x] != inf)
				ans.push_back(x);
		}

		sort(ans.begin(), ans.end());
		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}
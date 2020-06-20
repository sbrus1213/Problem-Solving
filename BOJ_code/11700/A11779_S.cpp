// BOJ 11779 최소비용 구하기 2
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int inf = 1e9;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<vector<int>> adj(n + 1, vector<int>(n + 1, inf));
	for (int i = 0; i < m; ++i) {
		int s, e, w; cin >> s >> e >> w;
		adj[s][e] = min(adj[s][e], w);
	}

	int s, e; cin >> s >> e;

	vector<int> dist(n + 1, inf), prv(n + 1);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		auto c = pq.top(); pq.pop();
		int d = c.first, cur = c.second;
		for (int nxt = 1; nxt <= n; ++nxt) {
			if (adj[cur][nxt] == inf) continue;
			if (dist[nxt] > dist[cur] + adj[cur][nxt]) {
				dist[nxt] = dist[cur] + adj[cur][nxt];
				prv[nxt] = cur;
				pq.push({ dist[nxt], nxt });
			}
		}
	}

	vector<int> ans;
	for (int x = e; x != s; x = prv[x])
		ans.push_back(x);
	ans.push_back(s);
	reverse(ans.begin(), ans.end());

	cout << dist[e] << '\n' << ans.size() << '\n';
	for (int x : ans)
		cout << x << ' ';
}
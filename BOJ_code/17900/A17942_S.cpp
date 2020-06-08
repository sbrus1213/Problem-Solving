// BOJ 17942 알고리즘 공부
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<int> gong(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> gong[i];

	int q; cin >> q;
	vector<vector<pii>> adj(n + 1);
	while (q--) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> vis(n + 1);
	for (int i = 1; i <= n; ++i)
		pq.push(pii(gong[i], i));

	int ans = -1, c = 0;
	while (!pq.empty() && c < m) {
		auto cc = pq.top(); pq.pop();
		if (vis[cc.second]) continue;
		c++;
		vis[cc.second] = 1;
		ans = max(ans, cc.first);
		for (auto nn : adj[cc.second]) {
			int nxt = nn.first;
			if (vis[nxt]) continue;
			if (gong[nxt] >= nn.second) gong[nxt] -= nn.second;
			else gong[nxt] = 0;
			pq.push(pii(gong[nxt], nxt));
		}
	}
	cout << ans;
}
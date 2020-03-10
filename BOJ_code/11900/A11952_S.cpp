// BOJ 11952 Á»ºñ
// BFS & Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
const ll inf = 1e15;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, s; cin >> n >> m >> k >> s;
	int p, q; cin >> p >> q;

	vector<int> dist(n + 1);
	vector<ll> cost(n + 1);
	queue<int> Q;
	for (int i = 0; i < k; ++i) {
		int z; cin >> z;
		dist[z] = s + 1;
		cost[z] = inf;
		Q.push(z);
	}

	vector<vector<int> > adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (dist[cur] == 1) continue;
		for (int nxt : adj[cur]) {
			if (dist[nxt]) continue;
			dist[nxt] = dist[cur] - 1;
			Q.push(nxt);
		}
	}

	for (int i = 2; i < n; ++i)
		if (!cost[i]) {
			if (dist[i]) cost[i] = q;
			else cost[i] = p;
		}

	vector<ll> dp(n + 1, inf);
	dp[1] = 0;

	priority_queue<pli, vector<pli >, greater<pli > > pq;
	vector<bool> chk(n + 1);
	pq.push(pli(dp[1], 1));
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (chk[cur.second]) continue;
		chk[cur.second] = true;
		for (int nxt : adj[cur.second]) {
			if (dp[nxt] > dp[cur.second] + cost[nxt]) {
				dp[nxt] = dp[cur.second] + cost[nxt];
				pq.push(pli(dp[nxt], nxt));
			}
		}
	}
	cout << dp[n];
}
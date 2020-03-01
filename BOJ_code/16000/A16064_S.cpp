// BOJ 16064 Coolest ski route
// Topology sort

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define BtoE(vec) vec.begin(), vec.end()
#define Pii pair<int, int>

vector<bool> vis;
vector<int> dist;
vector<vector<Pii > > adj;
vector<int> topo;

void top_sort(int curr) {
	vis[curr] = true;

	for (Pii next : adj[curr]) {
		if (!vis[next.first]) {
			top_sort(next.first);
		}
	}

	topo.push_back(curr);
}

void max_dist() {
	int len = topo.size();
	for (int i = len - 1; i >= 0; --i)
		for (Pii j : adj[topo[i]])
			dist[j.first] = max(dist[j.first], dist[topo[i]] + j.second);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	vis.resize(n + 1);
	dist.resize(n + 1);
	topo.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int s, t, c;

		cin >> s >> t >> c;
		adj[s].push_back(Pii(t, c));
	}

	fill(BtoE(vis), false);
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) top_sort(i);

	fill(BtoE(dist), 0);
	max_dist();

	int res = dist[1];
	for (int i = 2; i <= n; ++i)
		res = max(res, dist[i]);

	cout << res;
}
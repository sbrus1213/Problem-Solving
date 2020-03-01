// BOJ 1753 최단경로
// Dijkstra

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF (1e9+7)

struct vertex {
	int v, cost;
};
struct cmp {
	bool operator() (vertex a, vertex b) {
		return a.cost > b.cost;
	}
};

vector<int> dist;
vector<vector<vertex> > adj;
priority_queue<vertex, vector<vertex>, cmp> pq;

void dijkstra(int curr) {
	for (vertex next : adj[curr]) {
		if (dist[curr] != INF && dist[next.v] > dist[curr] + next.cost) {
			dist[next.v] = dist[curr] + next.cost;
			pq.push({ next.v, dist[next.v] });
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e, s;

	cin >> v >> e >> s;
	adj.resize(v + 1);
	dist.resize(v + 1);

	for (int i = 0; i < e; ++i) {
		int u, v, cost;

		cin >> u >> v >> cost;

		adj[u].push_back({ v, cost });
	}

	for (int i = 1; i <= v; ++i) dist[i] = INF;
	dist[s] = 0;

	pq.push({ s, 0 });
	while (!pq.empty()) {
		vertex tmp = pq.top(); pq.pop();

		dijkstra(tmp.v);
	}

	for (int i = 1; i <= v; ++i) {
		if (dist[i] != INF) cout << dist[i] << '\n';
		else cout << "INF\n";
	}
}
// BOJ 14611 월요병
// dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll inf = 1e15;

struct node {
	ll dist;
	int i, j;
};
bool operator< (node a, node b) {
	return a.dist > b.dist;
}

int ddi[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int ddj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int map[302][302];
vector<node> adj[302][302];
ll dist[302][302];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == -2)
				map[i][j] = 0;
		}

	map[0][0] = map[0][1] = map[1][0] = -1;
	map[n][m + 1] = map[n + 1][m] = map[n + 1][m + 1] = -1;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			if (map[i][j] == -1) continue;
			for (int k = 0; k < 8; ++k) {
				int ni = i + ddi[k], nj = j + ddj[k];
				if (ni < 0 || ni > n + 1) continue;
				if (nj < 0 || nj > m + 1) continue;
				if (map[ni][nj] == -1) continue;
				adj[i][j].push_back({ map[ni][nj], ni, nj });
			}
		}
	}

	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= m + 1; ++j)
			dist[i][j] = inf;

	dist[n + 1][0] = 0;
	priority_queue<node> pq;
	pq.push({ 0, n + 1 , 0 });
	while (!pq.empty()) {
		auto tmp = pq.top(); pq.pop();
		ll d = tmp.dist;
		int i = tmp.i, j = tmp.j;
		if (d > dist[i][j]) continue;
		for (auto& nxt : adj[i][j]) {
			int ni = nxt.i, nj = nxt.j;
			if (dist[ni][nj] > dist[i][j] + nxt.dist) {
				dist[ni][nj] = dist[i][j] + nxt.dist;
				pq.push({ dist[ni][nj], ni, nj });
			}
		}
	}

	if (dist[0][m + 1] == inf) cout << -1;
	else cout << dist[0][m + 1];
}
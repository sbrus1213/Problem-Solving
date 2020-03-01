// BOJ 1260 DFS¿Í BFS
// DFS & BFS

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, v;
bool adj[1001][1001], vis[1001];

void dfs(int curr) {
	vis[curr] = true;
	cout << curr << ' ';

	for (int next = 1; next <= n; ++next)
		if (adj[next][curr] && !vis[next])
			dfs(next);
}
void bfs(int start) {
	queue<int> Q;
	Q.push(start);
	vis[start] = true;
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		cout << curr << ' ';
		for (int next = 1; next <= n; ++next) {
			if (adj[next][curr] && !vis[next]) {
				Q.push(next);
				vis[next] = true;
			}
		}
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = adj[v][u] = true;
	}

	memset(vis, false, sizeof(vis));
	dfs(v);
	cout << '\n';
	memset(vis, false, sizeof(vis));
	bfs(v);
}
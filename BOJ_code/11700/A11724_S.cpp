// BOJ 11724 연결 요소의 개수
// BFS DFS

#include <iostream>
#include <vector>
using namespace std;

vector<int> vis;
vector<vector<int> > adj;

void dfs(int u) {
	for (int v : adj[u]) {
		if (vis[v]) continue;
		vis[v] = true;
		dfs(v);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	vis.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = true;
		dfs(i);
		ans++;
	}

	cout << ans;
}
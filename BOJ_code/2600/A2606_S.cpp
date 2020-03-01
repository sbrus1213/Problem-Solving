// BOJ 2606 바이러스
// BFS DFS

#include <iostream>
#include <vector>
using namespace std;

bool visi[101];
vector<vector<int>> adj(101);

void dfs(int curr) {
	for (int next : adj[curr]) {
		if (visi[next]) continue;
		visi[next] = true;
		dfs(next);
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	visi[1] = true;
	dfs(1);

	int ans = 0;
	for (int i = 2; i <= n; ++i) if (visi[i]) ans++;
	cout << ans;
}
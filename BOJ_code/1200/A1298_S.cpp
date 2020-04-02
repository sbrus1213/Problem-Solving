// BOJ 1298 노트북의 주인을 찾아서
// bipartite matching

#include <iostream>
#include <vector>
using namespace std;

vector<bool> vis;
vector<int> from;
vector<vector<int>> adj;

bool dfs(int cur) {
	if (vis[cur]) return false;
	vis[cur] = true;
	for (int next : adj[cur]) {
		if (from[next] == -1 || dfs(from[next])) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	adj = vector<vector<int> >(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	int ans = 0;
	vis = vector<bool>(n + 1);
	from = vector<int>(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		fill(vis.begin(), vis.end(), false);
		if (dfs(i)) ans++;
	}
	cout << ans;
}
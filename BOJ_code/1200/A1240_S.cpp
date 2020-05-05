// BOj 1240 노드사이의 거리
// BFS DFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using pii = pair<int, int>;

int ans, u, v;
bitset<1010> vis;
vector<vector<pii>> adj;

void dfs(int dep, int cur, int prv = -1) {
	vis[cur] = 1;
	if (cur == v) {
		ans = dep;
		return;
	}
	for (auto& nxt : adj[cur]) {
		if (nxt.first == prv || vis[nxt.first]) continue;
		dfs(dep + nxt.second, nxt.first, cur);
		if (ans > 0) return;
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	adj = vector<vector<pii>>(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		vis.reset();
		ans = -1;
		dfs(0, u);
		cout << ans << '\n';
	}
}
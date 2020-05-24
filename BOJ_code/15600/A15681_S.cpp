// BOJ 15681 트리와 쿼리
// DFS

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> sz;
int dfs(int cur, int prv) {
	sz[cur] = 1;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		sz[cur] += dfs(nxt, cur);
	}
	return sz[cur];
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, rt, q; cin >> n >> rt >> q;

	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	sz = vector<int>(n + 1);
	dfs(rt, 0);

	while (q--) {
		int srt; cin >> srt;
		cout << sz[srt] << '\n';
	}
}
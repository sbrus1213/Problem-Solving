// BOj 2644 촌수 계산
// tree

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101], vis(101);
bool dfs(int cur, int prv, int f) {
	vis[cur] = vis[prv] + 1;
	if (f == cur) return true;
	bool res = false;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		res |= dfs(nxt, cur, f);
	}
	return res;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int x, y; cin >> x >> y;

	int e; cin >> e;
	for (int i = 0; i < e; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (dfs(x, 0, y)) cout << vis[y] - vis[x];
	else cout << -1;
}
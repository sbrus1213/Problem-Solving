// BOJ 11725 트리의 부모 찾기
// tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> par;

void dfs(int cur, int prv = 0) {
	par[cur] = prv;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		if (par[nxt] == -1) dfs(nxt, cur);
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	par = vector<int>(n + 1, -1);
	dfs(1);

	for (int i = 2; i <= n; ++i) cout << par[i] << '\n';
}
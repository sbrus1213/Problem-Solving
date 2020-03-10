// 14866 산만한 고양이
// DFS tree

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj, tree;
vector<int> chk, par, sub_out, sub_in;

void dfs(int cur, int prev = 0) {
	chk[cur] = 1;
	par[cur] = prev;
	for (int nxt : adj[cur]) {
		if (nxt == prev) continue;
		if (chk[nxt] == 2) continue;;
		if (chk[nxt] == 1) {
			sub_out[cur]++;
			sub_in[nxt]++;
		}
		else {
			int t = sub_in[cur];
			dfs(nxt, cur);
			par[nxt] = sub_in[cur] - t;
			sub_out[cur] += sub_out[nxt];
			sub_in[cur] += sub_in[nxt];
			tree[cur].push_back(nxt);
		}
	}
	chk[cur] = 2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	adj = vector<vector<int> >(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	tree = vector<vector<int> >(n + 1);
	chk = sub_in = sub_out = par = vector<int>(n + 1);
	dfs(1);

	int back = m - (n - 1);
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		bool f = true;
		if (sub_out[i] < back) continue;
		for (int j : tree[i])
			if (sub_in[j] || sub_out[j] - par[j] >= 2) {
				f = false; break;
			}
		if (f) ans += i;
	}
	cout << ans;
}
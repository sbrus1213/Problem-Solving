// BOJ 11377 ¿­Ç÷°­È£ 3
// Bipartite Matching

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
vector<int> adj[2001];
int from[1001];
bool vis[2001];

bool dfs(int cur) {
	if (vis[cur]) return false;
	vis[cur] = true;
	for (auto& next : adj[cur]) {
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

	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		int c; cin >> c;
		while (c--) {
			int x; cin >> x;
			adj[i].push_back(x);
			adj[i + n].push_back(x);
		}
	}

	int res = 0, tmp = 0;
	fill(from, from + 1001, -1);
	for (int i = 1; i <= n; ++i) {
		fill(vis, vis + 2001, false);
		if (dfs(i)) res++;
	}
	for (int i = n + 1; i <= 2 * n; ++i) {
		fill(vis, vis + 2001, false);
		if (dfs(i)) tmp++;
		if (tmp == k) break;
	}

	cout << res + tmp;
}
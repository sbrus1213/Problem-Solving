// BOJ 10891 Cactus? Not Cactus?
// DFS spanning tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> dep, low;
int dfsn = 0;
bool cactus = true;

int dfs(int cur, int prv) {
	dep[cur] = dep[prv] + 1;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		else if (dep[nxt] && dep[nxt] > dep[cur]) continue;
		else if (dep[nxt] && dep[nxt] < dep[cur]) {
			if (low[cur]) {
				cactus = false;
				low[cur] = -1;
			}
			else low[cur] = nxt;
		}
		else {
			int res = dfs(nxt, cur);
			if (res < 0) low[cur] = -1;
			else if (res == 0);
			else {
				if (low[cur]) {
					cactus = false;
					low[cur] = -1;
				}
				else low[cur] = res;
			}
		}
	}
	return low[cur] == cur ? 0 : low[cur];
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	adj = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dep = vector<int>(n + 1);
	low = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i)
		if (!dep[i])
			dfs(i, 0);

	if (cactus) cout << "Cactus";
	else cout << "Not cactus";
}
// BOJ 11266 ´ÜÀýÁ¡
// BCC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
vector<vector<int> > adj;
vector<int> dfn, low;
vector<bool> visited, cut;

int dfs(int curr, int level) {

	visited[curr] = true;
	dfn[curr] = low[curr] = level;

	for (int next : adj[curr]) {
		if (!visited[next]) {
			if (level == 1) ++cnt;

			low[curr] = min(low[curr], dfs(next, level + 1));

			if (low[next] >= dfn[curr]) cut[curr] = true;
		}
		else
			low[curr] = min(low[curr], dfn[next]);
	}

	return low[curr];
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;

	cin >> v >> e;
	adj.resize(v + 1);
	visited.resize(v + 1);
	cut.resize(v + 1, false);
	dfn.resize(v + 1);
	low.resize(v + 1);

	for (int i = 0; i < e; ++i) {
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= v; ++i) {
		if (!visited[i]) {
			cnt = 0;

			dfs(i, 1);

			if (cnt >= 2) cut[i] = true;
			else cut[i] = false;
		}
	}

	int res = 0;
	for (int i = 1; i <= v; ++i) if (cut[i]) ++res;

	cout << res << '\n';
	for (int i = 1; i <= v; ++i) if (cut[i]) cout << i << ' ';
}
// BOJ 2188 축사 배정
// Bipartite matching

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> vis;
vector<int> from;
vector<vector<int>> cow;

bool dfs(int cur, int prev) {
	if (vis[cur]) return false;
	vis[cur] = true;
	for (int next : cow[cur]) {
		if (from[next] == -1 || dfs(from[next], next)) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	cow = vector<vector<int> >(n + 1);
	for (int i = 1; i <= n; ++i) {
		int c; cin >> c;
		for (int j = 0; j < c; ++j) {
			int x; cin >> x;
			cow[i].push_back(x);
		}
	}

	int res = 0;
	vis = vector<bool>(n + 1);
	from = vector<int>(m + 1, -1);
	for (int i = 1; i <= n; ++i) {
		fill(vis.begin(), vis.end(), false);
		if (dfs(i, 0)) res++;
	}

	cout << res;
}

/*
// Network flow - Edmonds-Karp Algorithm

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mxn 402

int n, m, S, E, res,
capacity[mxn][mxn], flow[mxn][mxn], previous[mxn];
vector<vector<int> > adj(mxn);

int residual(int u, int v) {
	return capacity[u][v] - flow[u][v];
}

void BFS() {
	queue<int> Q;

	memset(previous, -1, sizeof(previous));
	previous[S] = S;
	Q.push(S);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int next : adj[cur]) {
			if (previous[next] == -1 && residual(cur, next) > 0) {
				Q.push(next);
				previous[next] = cur;

				if (next == E) break;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int c, x;

		cin >> c;
		for (int j = 0; j < c; ++j) {
			cin >> x;
			adj[i].push_back(x + 200);
			adj[x + 200].push_back(i);
			capacity[i][x + 200] = 1;
		}
	}
	S = 0; E = 401;
	for (int i = 1; i <= n; ++i) {
		adj[S].push_back(i);
		capacity[S][i] = 1;
	}
	for (int j = 1; j <= m; ++j) {
		adj[j + 200].push_back(E);
		capacity[j + 200][E] = 1;
	}

	while (1) {
		BFS();

		if (previous[E] == -1) break;

		for (int i = E; i != S; i = previous[i]) {
			flow[previous[i]][i] += 1;
			flow[i][previous[i]] -= 1;
		}

		res += 1;
	}

	cout << res;
}
*/
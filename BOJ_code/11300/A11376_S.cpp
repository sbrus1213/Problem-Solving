// BOJ 11375 ¿­Ç÷°­È£2

// Network Flow - Edmonds-Karp Algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define mxn 2002
#define inf (1e9+7)

int cap[mxn][mxn], flow[mxn][mxn], pre[mxn], n, m, S, E, res;
vector<vector<int> > adj(mxn);

int residual(int u, int v) {
	return cap[u][v] - flow[u][v];
}

void BFS() {
	queue<int> Q;
	memset(pre, -1, sizeof(pre));
	pre[S] = S;
	Q.push(S);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int next : adj[cur]) {
			if (pre[next] == -1 && residual(cur, next) > 0) {
				Q.push(next);
				pre[next] = cur;

				if (next == E) break;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	S = 0, E = mxn - 1;
	for (int i = 1; i <= n; ++i) {
		int c, v;
		cin >> c;
		for (int j = 0; j < c; ++j) {
			cin >> v;

			adj[i].push_back(v + 1000);
			adj[v + 1000].push_back(i);

			cap[i][v + 1000] = 2;
		}
	}
	for (int i = 1; i <= n; ++i) {
		adj[S].push_back(i);
		cap[S][i] = 2;
	}
	for (int i = 1; i <= m; ++i) {
		adj[i + 1000].push_back(E);
		cap[i + 1000][E] = 1;
	}

	while (1) {
		BFS();

		if (pre[E] == -1) break;

		int bf = inf;
		for (int i = E; i != S; i = pre[i]) bf = min(bf, residual(pre[i], i));

		for (int i = E; i != S; i = pre[i]) {
			flow[pre[i]][i] += bf;
			flow[i][pre[i]] -= bf;
		}

		++res;
	}

	cout << res;
}

/*
// Bipartite Matching

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int matched[1001];
bool vis[1001];
bool can[1001][1001];

bool matching(int curr, int prev) {
	vis[curr] = true;

	for (int i = 1; i <= m; ++i) {
		if (i == prev) continue;

		if (can[curr][i] && matched[i] == -1) {
			matched[i] = curr;
			return true;
		}
	}

	for (int i = 1; i <= m; ++i) {
		if (i == prev) continue;

		if (can[curr][i] && !vis[matched[i]] && matching(matched[i], i)) {
			matched[i] = curr;
			return true;
		}
		else continue;
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int c;
		cin >> c;

		for (int j = 0; j < c; ++j) {
			int x;
			cin >> x;
			can[i][x] = true;
		}
	}

	int res = 0;
	memset(matched, -1, sizeof(matched));
	for (int i = 1; i <= n; ++i) {
		memset(vis, false, sizeof(vis));

		if (matching(i, 0)) res++;

		memset(vis, false, sizeof(vis));

		if (matching(i, 0)) res++;
	}

	cout << res;
}
*/
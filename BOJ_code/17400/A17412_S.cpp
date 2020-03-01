// BOJ 17412 도시 왕복하기 1
// network flow - edmond karp

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int mxn = 401;
const int INF = 1000000000;

int n, p, S, T;
int c[mxn][mxn], f[mxn][mxn];
vector<vector<int> > adj(mxn);

void addedge(int u, int v) {
	c[u][v] = 1;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

inline int residual(int cur, int next) {
	return c[cur][next] - f[cur][next];
}

int mxflow() {
	int totflow = 0;
	while (1) {
		vector<int> prev(mxn, -1);
		queue<int> q;
		q.push(S);
		while (!q.empty() && prev[T] == -1) {
			int cur = q.front(); q.pop();
			for (int next : adj[cur]) {
				if (prev[next] != -1) continue;
				if (residual(cur, next) <= 0) continue;
				prev[next] = cur;
				q.push(next);
				if (next == T) break;
			}
		}

		if (prev[T] == -1) break;

		for (int x = T; x != S; x = prev[x]) {
			f[prev[x]][x]++;
			f[x][prev[x]]--;
		}
		totflow++;
	}
	return totflow;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> p;

	for (int i = 0; i < p; ++i) {
		int u, v; cin >> u >> v;
		addedge(u, v);
	}

	cout << mxflow();
}
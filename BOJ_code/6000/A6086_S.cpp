// BOJ 6086 최대 유량
// Network flow - Edmonds-Karp Algorithm

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mxn 52

int n, S, E, res,
capacity[mxn][mxn], flow[mxn][mxn], previous[mxn];
vector<vector<int> > adj(mxn);

int node(char C) {
	return (C <= 'Z' ? C - 'A' : C - 'a' + 26);
}

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

	cin >> n;

	for (int i = 0; i < n; ++i) {
		char u, v;
		int w;

		cin >> u >> v >> w;

		adj[node(u)].push_back(node(v));
		adj[node(v)].push_back(node(u));
		capacity[node(u)][node(v)] += w;
		capacity[node(v)][node(u)] += w;
	}
	S = 0; E = 25;

	while (1) {
		int blocking_flow;

		BFS();

		if (previous[E] == -1) break;

		blocking_flow = residual(previous[E], E);
		for (int i = previous[E]; i != S; i = previous[i]) {
			blocking_flow = min(blocking_flow, residual(previous[i], i));
		}

		for (int i = E; i != S; i = previous[i]) {
			flow[previous[i]][i] += blocking_flow;
			flow[i][previous[i]] -= blocking_flow;
		}

		res += blocking_flow;
	}

	cout << res;
}
// BOJ 1658 µ≈¡ˆ ¿‚±‚
// Network flow - edmond karp

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

struct edge {
	int to, cap;
	edge* rev;
	edge() :edge(0, 0) {}
	edge(int t, int c) : to(t), cap(c), rev(NULL) {};
	int residual() { return cap; }
	void flow(int f) {
		cap -= f; rev->cap += f;
	}
};

int S, T, n, m;
vector<vector<edge*> > adj;

int mxflow() {
	int ret = 0;
	while (1) {
		vector<int> prev(n * m + n + m + 2, -1);
		vector<edge*> path(n * m + n + m + 2, NULL);
		queue<int> q; q.push(S);
		while (!q.empty() && prev[T] == -1) {
			int cur = q.front(); q.pop();
			for (auto& e : adj[cur]) {
				int next = e->to;
				if (prev[next] != -1) continue;
				if (e->cap == 0) continue;
				prev[next] = cur;
				path[next] = e;
				q.push(next);
				if (next == T) break;
			}
		}
		if (prev[T] == -1) break;
		int flow = INF + 1;
		for (int x = T; x != S; x = prev[x])
			flow = min(flow, path[x]->cap);
		for (int x = T; x != S; x = prev[x])
			path[x]->flow(flow);
		ret += flow;
	}
	return ret;
}

void addedge(int u, int v, int c1, int c2 = 0) {
	edge* e1 = new edge(v, c1), * e2 = new edge(u, c2);
	e1->rev = e2, e2->rev = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	S = 0, T = n * m + n + m + 1;

	adj.resize(n * m + n + m + 2);
	for (int i = 1; i <= m; ++i) {
		int x; cin >> x;
		addedge(n * m + n + i, T, x);
	}

	vector<int> idx(m + 1, -1);
	vector<vector<int> > buy(n);
	for (int i = 0; i < n; ++i) {
		int c, s = n * m + i + 1, x, f;
		cin >> c;
		for (int j = 0; j < c; ++j) {
			cin >> x;
			buy[i].push_back(x);
			if (idx[x] == -1) addedge(i * m + x, n * m + n + x, INF);
			else addedge(i * m + x, idx[x] * m + x, INF);
			idx[x] = i;
		}
		cin >> f;
		addedge(S, s, f);
		for (int j = 0; j < c; ++j) {
			if (!j) addedge(s, i * m + buy[i][j], INF);
			else addedge(s, i * m + buy[i][j], INF, INF);
			s = i * m + buy[i][j];
		}
	}
	cout << mxflow();
}
// BOJ 14286 간선 끊어가기 2
// min cut & max flow

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int mxn = 501;

struct edge {
	int to, cap;
	edge* rev;
	edge() :edge(0, 0) {}
	edge(int v, int w) :to(v), cap(w), rev(NULL) {}
	int residual() { return cap; }
	void add_flow(int f) {
		cap -= f;
		rev->cap += f;
	}
};

int n, m, S, T;
vector<vector<edge* > > adj(mxn);

void addedge(int f, int t, int c1, int c2 = 0) {
	edge* e = new edge(t, c1), * re = new edge(f, c2);
	e->rev = re; re->rev = e;
	adj[f].push_back(e);
	adj[t].push_back(re);
}

int mxflow() {
	int ret = 0;
	while (1) {
		vector<int> prev(mxn, -1);
		vector<edge*> path(mxn, NULL);
		queue<int> q;
		q.push(S);
		while (!q.empty() && prev[T] == -1) {
			int cur = q.front(); q.pop();
			for (auto& e : adj[cur]) {
				int next = e->to;
				if (prev[next] != -1) continue;
				if (e->residual() <= 0) continue;
				prev[next] = cur;
				path[next] = e;
				q.push(next);
				if (next == T) break;
			}
		}
		if (prev[T] == -1) break;
		for (int x = T; x != S; x = prev[x])
			path[x]->add_flow(1);
		ret++;
	}
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	cin >> S >> T;
	cout << mxflow();
}
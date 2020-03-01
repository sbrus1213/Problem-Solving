// BOJ 2316 도시 왕복하기 2
// network flow - edmond karp

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int mxn = 801;

struct edge {
	int to, cap, flow;
	edge* rev;
	edge() :edge(0, 0) {}
	edge(int v, int w) :to(v), cap(w), flow(0), rev(NULL) {}
	int residual() { return cap - flow; }
	void add_flow(int f) {
		flow += f;
		rev->flow -= f;
	}
};

int n, p, S, T;
vector<vector<edge* > > adj(mxn);

void addedge(int f, int t, int c) {
	edge* e = new edge(t, c), * re = new edge(f, 0);
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

		for (int x = T; x != S; x = prev[x]) {
			path[x]->add_flow(1);
		}
		ret++;
	}
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> p;

	for (int i = 0; i < p; ++i) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		if (u > 2) {
			addedge(u + n, v, 1);
			addedge(v + n, u, 1);
		}
		else if (u == 2) addedge(v + n, u, 1);
		else addedge(u + n, v, 1);
	}
	for (int i = 1; i <= n; ++i) {
		if (i <= 2) addedge(i, i + n, 2 * n);
		else addedge(i, i + n, 1);
	}
	S = 1; T = 2 + n;
	cout << mxflow();
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//const int mxn = 801;
//
//int n, p, S = 1, T = 2;
//int c[mxn][mxn], f[mxn][mxn];
//vector<vector<int> > adj(mxn);
//
//inline int residual(int cur, int next) {
//	return c[cur][next] - f[cur][next];
//}
//
//int mxflow() {
//	int ret = 0;
//
//	while (1) {
//		vector<int> prev(mxn, -1);
//
//		queue<int> q;
//		q.push(S);
//		while (!q.empty() && prev[T] == -1) {
//			int cur = q.front(); q.pop();
//			for (int next : adj[cur]) {
//				if (prev[next] != -1) continue;
//				if (residual(cur, next) <= 0) continue;
//				prev[next] = cur;
//				q.push(next);
//				if (next == T) break;
//			}
//		}
//
//		if (prev[T] == -1) break;
//
//		for (int x = T; x != S; x = prev[x]) {
//			f[prev[x]][x]++; f[x][prev[x]]--;
//		}
//		ret++;
//	}
//	return ret;
//}
//
//int main() {
//	cin.tie(NULL); cout.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	cin >> n >> p;
//
//	for (int i = 0; i < p; ++i) {
//		int u, v; cin >> u >> v;
//		if (u > v) swap(u, v);
//		if (u > 2) {
//			adj[u + n].push_back(v);
//			adj[v].push_back(u + n);
//			adj[v + n].push_back(u);
//			adj[u].push_back(v + n);
//			c[u + n][v] = c[v + n][u] = 1;
//		}
//		else if (u == 2) {
//			adj[v + n].push_back(u);
//			adj[u].push_back(v + n);
//			c[v + n][u] = 1;
//		}
//		else {
//			adj[u + n].push_back(v);
//			adj[v].push_back(u + n);
//			c[u + n][v] = 1;
//		}
//	}
//	for (int i = 1; i <= n; ++i) {
//		adj[i].push_back(i + n);
//		adj[i + n].push_back(i);
//		c[i][i + n] = 1;
//	}
//	c[1][1 + n] = c[2][2 + n] = 2 * n;
//	cout << mxflow();
//}
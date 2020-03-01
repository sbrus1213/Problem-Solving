// BOJ 7616 교실로 가는 길
// Network flow - max flow edmond karp

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int mxn = 10002;

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
int n, k, S, T;
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

	for (int cn = 1; ; cn++) {
		cin >> k >> n;
		if (!k && !n) break;

		cin.ignore(1);
		for (int i = 1; i <= 2 * n; ++i) adj[i].clear();
		for (int i = 1; i <= n; ++i) {
			string s;
			getline(cin, s);

			int tmp = 0;
			vector<bool> check(n + 1, false);
			for (int j = 0; j <= s.size(); ++j) {
				if (j == s.size()) {
					if (tmp > i && !check[tmp]) {
						addedge(i + n, tmp, 1);
						addedge(tmp + n, i, 1);
						check[tmp] = true;
					}
				}
				else if (s[j] == ' ') {
					if (tmp > i && !check[tmp]) {
						addedge(i + n, tmp, 1);
						addedge(tmp + n, i, 1);
						check[tmp] = true;
					}
					tmp = 0;
				}
				else tmp = tmp * 10 + s[j] - '0';
			}
		}
		for (int i = 3; i <= n; ++i)
			addedge(i, i + n, 1);

		S = 1 + n, T = 2;
		int totflow = mxflow();

		cout << "Case " << cn << ":\n";
		if (totflow < k) cout << "Impossible\n\n";
		else {
			for (int j = 0; j < k; ++j) {
				vector<int> prev(mxn, -1);
				queue<int> q;
				q.push(S);
				cout << 1 << ' ';
				while (!q.empty() && prev[T] == -1) {
					int cur = q.front(); q.pop();
					if (cur <= n) cout << cur << ' ';
					for (auto& e : adj[cur]) {
						int next = e->to;
						if (prev[next] != -1) continue;
						if (e->flow == 0) continue;
						prev[next] = cur;
						e->add_flow(-1);
						q.push(next);
						break;
					}
				}
				cout << 2 << '\n';
			}
		}
		cout << '\n';
	}
}
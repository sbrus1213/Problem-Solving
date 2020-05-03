// BOJ 14990 Crowd Control
// Binary search & DFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int v, c, id;
};

vector<vector<edge>> adj;
vector<int> vis;

void dfs(int cur, int c, int prv = -1) {
	vis[cur] = true;
	for (auto& nxt : adj[cur]) {
		if (nxt.v == prv || vis[nxt.v]) continue;
		if (nxt.c < c) continue;
		dfs(nxt.v, c, cur);
	}
}

bool fin;
vector<int> before, path;

bool get_path(int v, int cur, int c, int prv = -1) {
	vis[cur] = true;
	if (cur == v - 1) {
		fin = true;
		return true;;
	}
	for (auto& nxt : adj[cur]) {
		if (nxt.v == prv || vis[nxt.v]) continue;
		if (nxt.c < c) continue;
		if (fin) continue;
		if (get_path(v, nxt.v, c, cur))
			before[nxt.v] = cur;
	}
	if (fin) path[cur] = 1;
	return fin;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int v, e; cin >> v >> e;

	adj = vector<vector<edge>>(v);
	vector<int> elist;
	for (int i = 0; i < e; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c, i });
		adj[b].push_back({ a, c, i });
		elist.push_back(c);
	}

	sort(elist.begin(), elist.end());
	elist.erase(unique(elist.begin(), elist.end()), elist.end());

	int l = 0, r = elist.size();
	while (l + 1 < r) {
		int m = (l + r) / 2;
		int mid = elist[m];

		vis = vector<int>(v);
		dfs(0, mid);

		if (vis[v - 1]) l = m;
		else r = m;
	}

	vis = vector<int>(v);
	before = vector<int>(v);
	path = vector<int>(v);
	get_path(v, 0, elist[l]);

	vector<int> ans;
	for (int cur = v - 1, prv = v;; prv = cur, cur = before[cur]) {
		for (auto& nxt : adj[cur]) {
			if (nxt.v == prv || nxt.v == before[cur]) continue;
			ans.push_back(nxt.id);
		}
		if (!cur) break;
	}

	if (ans.empty()) {
		cout << "none";
		return 0;
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int ee : ans) cout << ee << ' ';
}
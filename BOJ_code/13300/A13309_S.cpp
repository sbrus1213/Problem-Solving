// BOJ 13309 Æ®¸®
// HLD & segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct seg {
	int n, half;
	vector<int> item;
	seg() :n(0) {}
	seg(int n_, vector<int>& val) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		for (int i = 1; i < n; ++i) item[i + half] = val[i];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
	}
	int sum(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += item[l++];
			if (!(r % 2)) res += item[r--];
			l >>= 1; r >>= 1;
		}
		return res;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] + item[idx * 2 + 1];
			idx >>= 1;
		}
	}
};
struct hld {
	vector<int> parent, depth, heavy, head, pos, dist, seg_dist;
	seg S;
	int n, dfsn = 0;

	int dfs(int cur, vector<vector<int> >& adj) {
		int size = 1, mxsize = 0;
		for (int nxt : adj[cur]) {
			depth[nxt] = depth[cur] + 1;
			parent[nxt] = cur;
			dist[nxt] = 1;
			int tmp = dfs(nxt, adj);
			size += tmp;
			if (mxsize < tmp) {
				mxsize = tmp; heavy[cur] = nxt;
			}
		}
		return size;
	}
	void decompose(int cur, int h, vector<vector<int> >& adj) {
		head[cur] = h; pos[cur] = ++dfsn;
		seg_dist[pos[cur]] = dist[cur];
		if (heavy[cur] != -1)
			decompose(heavy[cur], h, adj);
		for (int nxt : adj[cur])
			if (nxt != heavy[cur])
				decompose(nxt, nxt, adj);
	}
	hld(vector<vector<int> >& adj) {
		n = adj.size();
		parent = vector<int>(n);
		depth = vector<int>(n);
		heavy = vector<int>(n, -1);
		head = vector<int>(n);
		pos = vector<int>(n);
		dist = vector<int>(n);
		seg_dist = vector<int>(n);

		parent[1] = 0;
		dfs(1, adj);
		decompose(1, 1, adj);
		S = seg(n, seg_dist);
	}
	pii query(int l, int r) {
		int edges = 0, nodes = 0;
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			edges += S.sum(pos[head[r]], pos[r]);
			nodes += depth[r] - depth[head[r]] + 1;
		}
		if (depth[l] > depth[r]) swap(l, r);
		if (pos[l] != pos[r]) {
			edges += S.sum(pos[l] + 1, pos[r]);
			nodes += depth[r] - depth[l];
		}
		return pii(nodes + 1, edges);
	}
	void update(int i, int x = 0) {
		S.update(pos[i], x);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	vector<vector<int> > adj(n + 1);
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	hld H(adj);

	for (int i = 0; i < q; ++i) {
		int u, v, c; cin >> u >> v >> c;
		auto res = H.query(u, v);
		int _res = (res.first - 1 == res.second);
		if (c) {
			if (_res) H.update(u);
			else H.update(v);
		}
		if (_res) cout << "YES\n";
		else cout << "NO\n";
	}
}
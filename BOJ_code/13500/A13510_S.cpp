// BOJ 13510 Æ®¸®¿Í Äõ¸® 1
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
		for (int i = half - 1; i; --i) item[i] = max(item[i * 2], item[i * 2 + 1]);
	}
	int mxq(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res = max(res, item[l++]);
			if (!(r % 2)) res = max(res, item[r--]);
			l >>= 1; r >>= 1;
		}
		return res;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = max(item[idx * 2], item[idx * 2 + 1]);
			idx >>= 1;
		}
	}
};
struct hld {
	vector<int> parent, depth, heavy, head, pos, dist, seg_dist;
	seg S;
	int n, dfsn = 0;

	int dfs(int cur, vector<vector<pii> >& adj) {
		int size = 1, mxsize = 0, hvy;
		for (auto nxt : adj[cur]) {
			if (nxt.first == parent[cur]) continue;
			depth[nxt.first] = depth[cur] + 1;
			parent[nxt.first] = cur;
			dist[nxt.first] = nxt.second;
			int tmp = dfs(nxt.first, adj);
			size += tmp;
			if (mxsize < tmp) {
				mxsize = tmp; heavy[cur] = nxt.first;
			}
		}
		return size;
	}
	void decompose(int cur, int h, vector<vector<pii> >& adj) {
		head[cur] = h; pos[cur] = ++dfsn;
		seg_dist[pos[cur]] = dist[cur];
		if (heavy[cur] != -1)
			decompose(heavy[cur], h, adj);
		for (auto nxt : adj[cur])
			if (nxt.first != parent[cur] && nxt.first != heavy[cur])
				decompose(nxt.first, nxt.first, adj);
	}
	hld(vector<vector<pii> >& adj) {
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
	int query(int l, int r) {
		int res = 0;
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			res = max(res, S.mxq(pos[head[r]], pos[r]));
		}
		if (depth[l] > depth[r]) swap(l, r);
		if (pos[l] != pos[r])
			res = max(res, S.mxq(pos[l] + 1, pos[r]));
		return res;
	}
	void update(pii p, int x) {
		int i = depth[p.first] > depth[p.second] ? p.first : p.second;
		S.update(pos[i], x);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<vector<pii > > adj(n + 1);
	vector<pii> e(n);
	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(pii(v, w));
		adj[v].push_back(pii(u, w));
		e[i] = pii(u, v);
	}
	hld H(adj);

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int c, a, b; cin >> c >> a >> b;
		if (c == 1) H.update(e[a], b);
		else cout << H.query(a, b) << '\n';
	}
}
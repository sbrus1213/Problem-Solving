// BOJ 18227 성대나라의 물탱크
// HLD & segment tree & lazy propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct seg {
	int n, half;
	vector<int> item, lazy;
	seg() : seg(0) {}
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		lazy.resize(half * 2);
	}
	void propagate(int node, int ns, int ne) {
		if (!lazy[node]) return;
		item[node] += (ne - ns + 1) * lazy[node];
		if (ns != ne) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	int sum(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (l <= ns && ne <= r) return item[node];
		if (ne < l || r < ns) return 0;
		int mid = (ns + ne) / 2;
		return sum(node * 2, ns, mid, l, r) + sum(node * 2 + 1, mid + 1, ne, l, r);
	}
	void update(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (ne < l || r < ns) return;
		if (l <= ns && ne <= r) {
			lazy[node] += 1;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2 + 1, mid + 1, ne, l, r);
		update(node * 2, ns, mid, l, r);
		item[node] = item[node * 2] + item[node * 2 + 1];
	}
};
struct hld {
	vector<int> parent, depth, heavy, head, pos;
	vector<int> seg_cnt;
	seg S;
	int n, dfsn = 0, rt;

	int dfs(int cur, vector<vector<int> >& adj) {
		int size = 1, mxsize = 0;
		for (int nxt : adj[cur]) {
			if (nxt == parent[cur]) continue;
			depth[nxt] = depth[cur] + 1;
			parent[nxt] = cur;
			int tmp = dfs(nxt, adj);
			size += tmp;
			if (mxsize < tmp) {
				mxsize = tmp; heavy[cur] = nxt;
			}
		}
		return size;
	}
	void decompose(int cur, int h, vector<vector<int> >& adj) {
		head[cur] = h; pos[cur] = dfsn++;
		if (heavy[cur] != -1)
			decompose(heavy[cur], h, adj);
		for (int nxt : adj[cur])
			if (nxt != parent[cur] && nxt != heavy[cur])
				decompose(nxt, nxt, adj);
	}
	hld(vector<vector<int> >& adj, int rt_) {
		n = adj.size();
		parent = vector<int>(n);
		depth = vector<int>(n);
		heavy = vector<int>(n, -1);
		head = vector<int>(n);
		pos = vector<int>(n);
		seg_cnt = vector<int>(n);

		rt = rt_;
		depth[rt] = 1;
		parent[rt] = -1;
		dfs(rt, adj);
		decompose(rt, rt, adj);
		S = seg(n);
	}
	ll query(int i) {
		ll res = S.sum(1, 0, n - 1, pos[i], pos[i]);
		return res * depth[i];
	}
	void update(int r) {
		for (; rt != head[r]; r = parent[head[r]])
			S.update(1, 0, n - 1, pos[head[r]], pos[r]);
		S.update(1, 0, n - 1, pos[rt], pos[r]);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, rt; cin >> n >> rt;
	rt--;
	vector<vector<int> >adj(n);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	hld H(adj, rt);

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int c, j; cin >> c >> j;
		j--;
		if (c == 1) H.update(j);
		else cout << H.query(j) << '\n';
	}
}
// BOJ 5916 ³óÀå °ü¸®
// HLD & segment tree & lazy propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct seg {
	int n, half;
	vector<ll> item, lazy;
	seg() : seg(1) {}
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
	ll sum(int node, int ns, int ne, int l, int r) {
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
struct HLD {
	vector<int> parent, depth, heavy, head, pos, dist, seg_dist;
	seg S;
	int n, dfsn = 0;

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
	HLD(vector<vector<int> >& adj) {
		n = adj.size();
		parent = vector<int>(n);
		depth = vector<int>(n);
		heavy = vector<int>(n, -1);
		head = vector<int>(n);
		pos = vector<int>(n);

		parent[0] = -1;
		dfs(0, adj);
		decompose(0, 0, adj);
		S = seg(n);
	}
	ll query(int l, int r) {
		ll res = 0;
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			res += S.sum(1, 0, n - 1, pos[head[r]], pos[r]);
		}
		if (depth[l] > depth[r]) swap(l, r);
		if (pos[l] != pos[r])
			res += S.sum(1, 0, n - 1, pos[l] + 1, pos[r]);
		return res;
	}
	void update(int l, int r) {
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			S.update(1, 0, n - 1, pos[head[r]], pos[r]);
		}
		if (depth[l] > depth[r]) swap(l, r);
		if (pos[l] != pos[r])
			S.update(1, 0, n - 1, pos[l] + 1, pos[r]);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	vector<vector<int> > adj(n);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	HLD hld(adj);

	for (int i = 0; i < q; ++i) {
		char c; int u, v; cin >> c >> u >> v;
		u--; v--;
		if (c == 'P') {
			hld.update(u, v);
		}
		else {
			cout << hld.query(u, v) << '\n';
		}
	}
}
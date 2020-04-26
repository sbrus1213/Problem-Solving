// BOJ 17429 국제 메시 기구
// HLD & lazy propagation

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
const ll mod = 4294967296;

struct lseg {
	int n, half;
	vector<ll> item, mlazy, plazy;
	lseg() : lseg(1) {}
	lseg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item = vector<ll>(half << 1);
		mlazy = vector<ll>(half << 1, 1);
		plazy = vector<ll>(half << 1);
	}
	void propagate(int node, int ns, int ne) {
		if (mlazy[node] == 1 && !plazy[node]) return;
		item[node] = ((item[node] * mlazy[node]) % mod + (ll)(ne - ns + 1) * plazy[node]) % mod;
		if (ns != ne) {
			mlazy[node * 2] = (mlazy[node * 2] * mlazy[node]) % mod;
			mlazy[node * 2 + 1] = (mlazy[node * 2 + 1] * mlazy[node]) % mod;
			plazy[node * 2] = (plazy[node * 2] * mlazy[node] + plazy[node]) % mod;
			plazy[node * 2 + 1] = (plazy[node * 2 + 1] * mlazy[node] + plazy[node]) % mod;
		}
		mlazy[node] = 1; plazy[node] = 0;
	}
	ll sum(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (l <= ns && ne <= r) return item[node];
		if (ne < l || r < ns) return 0;
		int mid = (ns + ne) / 2;
		return (sum(node * 2, ns, mid, l, r) + sum(node * 2 + 1, mid + 1, ne, l, r)) % mod;
	}
	void update(int node, int ns, int ne, int l, int r, ll mul, ll add) {
		propagate(node, ns, ne);
		if (ne < l || r < ns) return;
		if (l <= ns && ne <= r) {
			mlazy[node] = (mlazy[node] * mul) % mod;
			plazy[node] = (plazy[node] * mul + add) % mod;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2, ns, mid, l, r, mul, add);
		update(node * 2 + 1, mid + 1, ne, l, r, mul, add);
		item[node] = (item[node * 2] + item[node * 2 + 1]) % mod;
	}
};
struct HLD {
	vector<int> parent, depth, heavy, head, pos, mpos;
	int n, dfsn;
	lseg S;

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
		mpos[cur] = size - 1;
		return size;
	}
	void decompose(int cur, int h, vector<vector<int> >& adj) {
		head[cur] = h; pos[cur] = dfsn++; mpos[cur] += pos[cur];
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
		mpos = vector<int>(n);
		S = lseg(n);

		parent[0] = -1;
		dfs(0, adj);
		dfsn = 0;
		decompose(0, 0, adj);
	}
	void path_update(int l, int r, ll mul, ll add) {
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			S.update(1, 0, n - 1, pos[head[r]], pos[r], mul, add);
		}
		if (depth[l] > depth[r]) swap(l, r);
		S.update(1, 0, n - 1, pos[l], pos[r], mul, add);
	}
	ll path_sum(int l, int r) {
		ll res = 0;
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			res = (res + S.sum(1, 0, n - 1, pos[head[r]], pos[r])) % mod;
		}
		if (depth[l] > depth[r]) swap(l, r);
		res = (res + S.sum(1, 0, n - 1, pos[l], pos[r])) % mod;
		return res;
	}
	void sub_update(int rt, ll mul, ll add) {
		S.update(1, 0, n - 1, pos[rt], mpos[rt], mul, add);
	}
	ll sub_sum(int rt) {
		return S.sum(1, 0, n - 1, pos[rt], mpos[rt]);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	vector<vector<int>> adj(n);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	HLD hld(adj);
	for (int i = 0; i < q; ++i) {
		int c; cin >> c;
		if (c == 1) {
			int x; ll v; cin >> x >> v; x--;
			hld.sub_update(x, 1, v);
		}
		else if (c == 2) {
			int x, y; ll v; cin >> x >> y >> v; x--; y--;
			hld.path_update(x, y, 1, v);
		}
		else if (c == 3) {
			int x; ll v; cin >> x >> v; x--;
			hld.sub_update(x, v, 0);
		}
		else if (c == 4) {
			int x, y; ll v; cin >> x >> y >> v; x--; y--;
			hld.path_update(x, y, v, 0);
		}
		else if (c == 5) {
			int x; cin >> x; x--;
			cout << hld.sub_sum(x) << '\n';
		}
		else if (c == 6) {
			int x, y; cin >> x >> y; x--; y--;
			cout << hld.path_sum(x, y) << '\n';
		}
	}
}
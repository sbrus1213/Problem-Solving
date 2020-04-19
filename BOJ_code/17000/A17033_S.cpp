// BOJ 17033 Cow Land
// HLD & segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct seg {
	int n, half;
	vector<ll> item;
	seg() :n(0) {}
	seg(int n_, vector<ll>& val) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		for (int i = 1; i < n; ++i) item[i + half] = val[i];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] ^ item[i * 2 + 1];
	}
	ll xorq(int l, int r) {
		ll res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res ^= item[l++];
			if (!(r % 2)) res ^= item[r--];
			l >>= 1; r >>= 1;
		}
		return res;
	}
	void update(int idx, ll x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] ^ item[idx * 2 + 1];
			idx >>= 1;
		}
	}
};
struct hld {
	vector<int> parent, depth, heavy, head, pos;
	vector<ll> enj, seg_enj;
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
		head[cur] = h; pos[cur] = ++dfsn;
		seg_enj[pos[cur]] = enj[cur];
		if (heavy[cur] != -1)
			decompose(heavy[cur], h, adj);
		for (int nxt : adj[cur])
			if (nxt != parent[cur] && nxt != heavy[cur])
				decompose(nxt, nxt, adj);
	}
	hld(vector<vector<int> >& adj, vector<ll>& enj_) : enj(move(enj_)) {
		n = adj.size();
		parent = vector<int>(n);
		depth = vector<int>(n);
		heavy = vector<int>(n, -1);
		head = vector<int>(n);
		pos = vector<int>(n);
		seg_enj = vector<ll>(n);

		parent[1] = 0;
		dfs(1, adj);
		decompose(1, 1, adj);
		S = seg(n, seg_enj);
	}
	ll query(int l, int r) {
		ll res = 0;
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			res ^= S.xorq(pos[head[r]], pos[r]);
		}
		if (depth[l] > depth[r]) swap(l, r);
		res ^= S.xorq(pos[l], pos[r]);
		return res;
	}
	void update(int i, ll x) {
		S.update(pos[i], x);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	vector<vector<int> >adj(n + 1);
	vector<ll> enj(n + 1);
	for (int i = 1; i <= n; ++i) cin >> enj[i];
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	hld H(adj, enj);

	for (int i = 0; i < q; ++i) {
		ll c, a, b; cin >> c >> a >> b;
		if (c == 1) H.update(a, b);
		else cout << H.query(a, b) << '\n';
	}
}
// BOJ 2927 ³²±Ø Å½Çè
// HLD & union find

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct query {
	char c;
	int a, b;
	query() :query('b', 0, 0) {}
	query(char _c, int _a, int _b) :c(_c), a(_a), b(_b) {}
};
struct HLD {
	vector<int> parent, depth, heavy, head, pos, sum_seg;
	int n, half, dfsn;

	int dfs(int cur, vector<vector<pii> >& adj) {
		int size = 1, mxsize = 0;
		for (auto nxt : adj[cur]) {
			if (nxt.first == parent[cur]) continue;
			depth[nxt.first] = depth[cur] + 1;
			parent[nxt.first] = cur;
			int tmp = dfs(nxt.first, adj);
			size += tmp;
			if (mxsize < tmp) {
				mxsize = tmp; heavy[cur] = nxt.first;
			}
		}
		return size;
	}
	void decompose(int cur, int h, vector<vector<pii> >& adj) {
		head[cur] = h; pos[cur] = dfsn++;
		if (heavy[cur] != -1)
			decompose(heavy[cur], h, adj);
		for (auto nxt : adj[cur])
			if (nxt.first != parent[cur] && nxt.first != heavy[cur])
				decompose(nxt.first, nxt.first, adj);
	}
	HLD(vector<vector<pii> >& adj, vector<int>& pen) {
		n = adj.size();
		parent = vector<int>(n);
		depth = vector<int>(n);
		heavy = vector<int>(n, -1);
		head = vector<int>(n);
		pos = vector<int>(n);

		for (half = 1; half < n; half <<= 1);
		sum_seg = vector<int>(half * 2);

		for (int i = 0; i < n; ++i) {
			if (!depth[i]) {
				depth[i] = 1; parent[i] = -1;
				dfs(i, adj);
			}
		}
		dfsn = 0;
		for (int i = 0; i < n; ++i)
			if (depth[i] == 1)
				decompose(i, i, adj);

		for (int i = 0; i < n; ++i)
			sum_seg[pos[i] + half] = pen[i];
		for (int i = half - 1; i; --i)
			sum_seg[i] = sum_seg[i * 2] + sum_seg[i * 2 + 1];
	}
	int seg_sum(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += sum_seg[l++];
			if (!(r % 2)) res += sum_seg[r--];
			l >>= 1; r >>= 1;
		}
		return res;
	}
	int sum_query(int l, int r) {
		int res = 0;
		for (; head[l] != head[r]; r = parent[head[r]]) {
			if (depth[head[l]] > depth[head[r]]) swap(l, r);
			res += seg_sum(pos[head[r]], pos[r]);
		}
		if (depth[l] > depth[r]) swap(l, r);
		res += seg_sum(pos[l], pos[r]);
		return res;
	}
	void update(int idx, int x) {
		idx = pos[idx] + half;
		sum_seg[idx] = x;
		idx /= 2;
		while (idx) {
			sum_seg[idx] = sum_seg[idx * 2] + sum_seg[idx * 2 + 1];
			idx /= 2;
		}
	}
};

vector<int> par;
int find(int i) {
	if (par[i] < 0) return i;
	else return par[i] = find(par[i]);
}
bool merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> pen(n);
	for (int i = 0; i < n; ++i) cin >> pen[i];

	int q; cin >> q;
	vector<query> qry(q + 1);
	par = vector<int>(n, -1);
	vector<vector<pii>> adj(n);
	for (int i = 1; i <= q; ++i) {
		string c; int a, b; cin >> c >> a >> b;
		if (c[0] == 'b') {
			a--; b--;
			if (merge(a, b)) {
				adj[a].push_back({ b, i });
				adj[b].push_back({ a, i });
			}
		}
		else if (c[0] == 'p') {
			a--;
		}
		else if (c[0] == 'e') {
			a--; b--;
		}
		qry[i] = query(c[0], a, b);
	}

	HLD hld(adj, pen);

	par = vector<int>(n, -1);
	for (int i = 1; i <= q; ++i) {
		auto qr = qry[i];
		if (qr.c == 'b') {
			if (merge(qr.a, qr.b)) cout << "yes\n";
			else cout << "no\n";
		}
		else if (qr.c == 'p') {
			hld.update(qr.a, qr.b);
		}
		else if (qr.c == 'e') {
			if (find(qr.a) != find(qr.b))
				cout << "impossible\n";
			else  cout << hld.sum_query(qr.a, qr.b) << '\n';
		}
	}
}
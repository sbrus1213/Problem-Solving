// BOJ 14268 내리 칭찬 2
// Segment tree & Lazy Propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Seg {
	int n, half;
	vector<int> item, lazy;
	Seg(int _n) : n(_n) {
		for (half = 1; half < n; half <<= 1);
		item = vector<int>(half * 2);
		lazy = vector<int>(half * 2);
	}
	void prop(int node, int ns, int ne) {
		if (!lazy[node]) return;
		item[node] += (ne - ns + 1) * lazy[node];
		if (ns != ne) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	int sum(int node, int ns, int ne, int l, int r) {
		prop(node, ns, ne);
		if (l <= ns && ne <= r) return item[node];
		else if (r < ns || ne < l) return 0;
		int mid = (ns + ne) / 2;
		return sum(node * 2, ns, mid, l, r) + sum(node * 2 + 1, mid + 1, ne, l, r);
	}
	int sum(int l, int r) {
		return sum(1, 0, n - 1, l, r);
	}
	void update(int node, int ns, int ne, int l, int r, int diff) {
		prop(node, ns, ne);
		if (l <= ns && ne <= r) {
			lazy[node] += diff;
			prop(node, ns, ne);
			return;
		}
		else if (r < ns || ne < l) return;
		int mid = (ns + ne) / 2;
		update(node * 2, ns, mid, l, r, diff);
		update(node * 2 + 1, mid + 1, ne, l, r, diff);
		item[node] = item[node * 2] + item[node * 2 + 1];
	}
	void update(int l, int r, int diff) {
		update(1, 0, n - 1, l, r, diff);
	}
};

vector<vector<int>> adj;
vector<int> id, last;
int dfsn;

int dfs(int cur) {
	id[cur] = last[cur] = dfsn++;
	for (int nxt : adj[cur])
		last[cur] = dfs(nxt);
	return last[cur];
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	adj = vector<vector<int>>(n + 1);
	for (int i = 1; i <= n; ++i) {
		int p; cin >> p;
		if (i > 1) adj[p].push_back(i);
	}

	id = last = vector<int>(n + 1);
	dfs(1);

	Seg seg(n);
	while (m--) {
		int c; cin >> c;
		if (c == 1) {
			int i, w; cin >> i >> w;
			seg.update(id[i], last[i], w);
		}
		else if (c == 2) {
			int i; cin >> i;
			cout << seg.sum(id[i], id[i]) << '\n';
		}
	}
}
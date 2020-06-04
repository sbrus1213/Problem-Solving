// BOJ 14287 내리 칭찬 3
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Seg {
	int n, half;
	vector<int> item;
	Seg(int _n) : n(_n) {
		for (half = 1; half < n; half <<= 1);
		item = vector<int>(half * 2);
	}
	int sum(int node, int ns, int ne, int l, int r) {
		if (l <= ns && ne <= r) return item[node];
		else if (r < ns || ne < l) return 0;
		int mid = (ns + ne) / 2;
		return sum(node * 2, ns, mid, l, r) + sum(node * 2 + 1, mid + 1, ne, l, r);
	}
	int sum(int l, int r) {
		return sum(1, 0, n - 1, l, r);
	}
	void update(int node, int ns, int ne, int id, int diff) {
		if (ns == ne) {
			item[node] += diff;
			return;
		}
		int mid = (ns + ne) / 2;
		if (id <= mid) update(node * 2, ns, mid, id, diff);
		else update(node * 2 + 1, mid + 1, ne, id, diff);
		item[node] = item[node * 2] + item[node * 2 + 1];
	}
	void update(int id, int diff) {
		update(1, 0, n - 1, id, diff);
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
			seg.update(id[i], w);
		}
		else if (c == 2) {
			int i; cin >> i;
			cout << seg.sum(id[i], last[i]) << '\n';
		}
	}
}
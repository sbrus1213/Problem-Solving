// BOJ 1395 ½ºÀ§Ä¡
// Segment tree & Lazy Propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct seg {
	int n, half;
	vector<int> item, lazy;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		lazy.resize(half * 2);
	}
	void propagate(int node, int ns, int ne) {
		if (!lazy[node]) return;
		if (lazy[node] % 2) item[node] = (ne - ns + 1) - item[node];
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
			item[node] = (ne - ns + 1) - item[node];
			if (ns != ne) {
				lazy[node * 2]++;
				lazy[node * 2 + 1]++;
			}
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2, ns, mid, l, r);
		update(node * 2 + 1, mid + 1, ne, l, r);
		item[node] = item[node * 2] + item[node * 2 + 1];
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	seg S(n);
	for (int i = 0; i < q; ++i) {
		int comm, l, r;
		cin >> comm >> l >> r;
		if (!comm) S.update(1, 1, n, l, r);
		else cout << S.sum(1, 1, n, l, r) << '\n';
	}
}
// BOJ 10277 JuQueen
// Segment tree & Lazy Propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 100000;

struct seg {
	int n, half;
	vector<int> lazy, min_item, max_item;
	seg(int n_) :n(n_) {
		for (half = 1; half < n; half <<= 1);
		min_item.resize(half * 2);
		max_item.resize(half * 2);
		lazy.resize(half * 2);
	}
	void propagate(int node, int ns, int ne) {
		if (!lazy[node]) return;
		min_item[node] += lazy[node];
		max_item[node] += lazy[node];
		if (ns != ne) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	int max_query(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (l <= ns && ne <= r) return  max_item[node];
		if (ne < l || r < ns) return -1;
		int mid = (ns + ne) / 2;
		return max(max_query(node * 2, ns, mid, l, r), (max_query(node * 2 + 1, mid + 1, ne, l, r)));
	}
	int min_query(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (l <= ns && ne <= r) return  min_item[node];
		if (ne < l || r < ns) return INF;
		int mid = (ns + ne) / 2;
		return min(min_query(node * 2, ns, mid, l, r), (min_query(node * 2 + 1, mid + 1, ne, l, r)));
	}
	void update(int node, int ns, int ne, int l, int r, int diff) {
		propagate(node, ns, ne);
		if (ne < l || r < ns) return;
		if (l <= ns && ne <= r) {
			max_item[node] += diff;
			min_item[node] += diff;
			if (ns != ne) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2, ns, mid, l, r, diff);
		update(node * 2 + 1, mid + 1, ne, l, r, diff);
		max_item[node] = max(max_item[node * 2], max_item[node * 2 + 1]);
		min_item[node] = min(min_item[node * 2], min_item[node * 2 + 1]);
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, lim, q;
	cin >> n >> lim >> q;

	seg S(n);
	for (int i = 0; i < q; ++i) {
		string comm;
		int x, a, b, s, tmp;
		cin >> comm;

		if (comm == "state") {
			cin >> x;
			cout << S.max_query(1, 0, n - 1, x, x) << '\n';
		}
		else if (comm == "groupchange") {
			cin >> a >> b >> s;
			if (s > 0) {
				tmp = S.max_query(1, 0, n - 1, a, b);
				s = min(lim - tmp, s);
			}
			else {
				tmp = S.min_query(1, 0, n - 1, a, b);
				s = -min(tmp, -s);
			}
			S.update(1, 0, n - 1, a, b, s);
			cout << s << '\n';
		}
		else {
			cin >> x >> s;
			tmp = S.max_query(1, 0, n - 1, x, x);
			if (s > 0) s = min(lim - tmp, s);
			else s = -min(tmp, -s);
			S.update(1, 0, n - 1, x, x, s);
			cout << s << '\n';
		}
	}
}
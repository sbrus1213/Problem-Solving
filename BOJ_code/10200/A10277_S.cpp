// BOJ 10277 JuQueen
// Segment tree & Lazy Propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 100000;

pii minmax__(pii a, pii b) {
	pii res;
	res.first = max(a.first, b.first);
	res.second = min(a.second, b.second);
	return res;
}

struct seg {
	int n, half;
	vector<pii > item;
	vector<int> lazy;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		lazy.resize(half * 2);
	}
	void propagate(int node, int ns, int ne) {
		if (!lazy[node]) return;
		item[node].first += lazy[node];
		item[node].second += lazy[node];
		if (ns != ne) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	pii query(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (l <= ns && ne <= r) return item[node];
		if (ne < l || r < ns) return pii(-1, INF);
		int mid = (ns + ne) / 2;
		return minmax__(query(node * 2, ns, mid, l, r), query(node * 2 + 1, mid + 1, ne, l, r));
	}
	void update(int node, int ns, int ne, int l, int r, int diff) {
		propagate(node, ns, ne);
		if (ne < l || r < ns) return;
		if (l <= ns && ne <= r) {
			item[node].first += diff;
			item[node].second += diff;
			if (ns != ne) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2 + 1, mid + 1, ne, l, r, diff);
		update(node * 2, ns, mid, l, r, diff);
		item[node] = minmax__(item[node * 2], item[node * 2 + 1]);
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
		int x, a, b, s;
		pii tmp;
		cin >> comm;

		if (comm == "state") {
			cin >> x;
			tmp = S.query(1, 0, n - 1, x, x);
			cout << tmp.first << '\n';
		}
		else if (comm == "groupchange") {
			cin >> a >> b >> s;
			tmp = S.query(1, 0, n - 1, a, b);
			if (s > 0) s = min(lim - tmp.first, s);
			else if (s < 0) s = -min(tmp.second, -s);
			S.update(1, 0, n - 1, a, b, s);
			cout << s << '\n';
		}
		else {
			cin >> x >> s;
			tmp = S.query(1, 0, n - 1, x, x);
			if (s > 0) s = min(lim - tmp.first, s);
			else if (s < 0) s = -min(tmp.second, -s);
			S.update(1, 0, n - 1, x, x, s);
			cout << s << '\n';
		}
	}
}
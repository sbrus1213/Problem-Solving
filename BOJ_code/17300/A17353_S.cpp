// BOJ 17353 하늘에서 떨어지는 1, 2, ..., R-L+1 개의 별
// Segment tree & Lazy Propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct seg {
	int n, half;
	vector<ll> item;
	vector<pll > lazy;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		lazy.resize(half * 2);
	}
	ll init(int node, int ns, int ne, vector<ll>& arr) {
		if (ns == ne) return item[node] = arr[ns];
		int mid = (ns + ne) / 2;
		return item[node] = init(node * 2, ns, mid, arr) + init(node * 2 + 1, mid + 1, ne, arr);
	}
	void propagate(int node, int ns, int ne) {
		if (!lazy[node].second) return;
		item[node] += (2 * lazy[node].first + (ne - ns) * lazy[node].second) * (ne - ns + 1) / 2;
		if (ns != ne) {
			int mid = (ns + ne) / 2;
			lazy[node * 2].first += lazy[node].first;
			lazy[node * 2 + 1].first += lazy[node].first + (mid - ns + 1) * lazy[node].second;
			lazy[node * 2].second += lazy[node].second;
			lazy[node * 2 + 1].second += lazy[node].second;
		}
		lazy[node] = pll(0, 0);
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
			item[node] += (ns + ne - 2 * l + 2) * (ne - ns + 1) / 2;
			if (ns != ne) {
				int mid = (ns + ne) / 2;
				lazy[node * 2].first += (ll)ns - l + 1;
				lazy[node * 2 + 1].first += (ll)mid + 1 - l + 1;
				lazy[node * 2].second += 1;
				lazy[node * 2 + 1].second += 1;
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
	cin >> n;

	seg S(n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	S.init(1, 0, n - 1, arr);

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int comm, l, r, x;
		cin >> comm;
		if (comm == 1) {
			cin >> l >> r;
			l--; r--;
			S.update(1, 0, n - 1, l, r);
		}
		else {
			cin >> x;
			x--;
			cout << S.sum(1, 0, n - 1, x, x) << '\n';
		}
	}
}
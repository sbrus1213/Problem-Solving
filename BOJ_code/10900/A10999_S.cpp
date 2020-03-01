// BOJ 10999 구간 합 구하기 2
// Segment tree & Lazy Propagation

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct seg {
	int n, half;
	vector<ll> item, lazy;
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
	void update(int node, int ns, int ne, int l, int r, ll diff) {
		propagate(node, ns, ne);
		if (ne < l || r < ns) return;
		if (l <= ns && ne <= r) {
			item[node] += (ne - ns + 1) * diff;
			if (ns != ne) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2 + 1, mid + 1, ne, l, r, diff);
		update(node * 2, ns, mid, l, r, diff);
		item[node] = item[node * 2] + item[node * 2 + 1];
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	seg S(n);
	vector<ll> arr(n + 1);
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	S.init(1, 1, n, arr);

	for (int i = 0; i < m + k; ++i) {
		int comm, a, b;
		ll c;
		cin >> comm >> a >> b;
		if (comm == 1) {
			cin >> c;
			S.update(1, 1, n, a, b, c);
		}
		else cout << S.sum(1, 1, n, a, b) << '\n';
	}
}
// BOJ 13925 ¼ö¿­°ú Äõ¸® 13
// Lazy propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const ll MOD = 1e9 + 7;

struct seg {
	int n, half;
	vector<ll> item;
	vector<pll> lazy;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
		lazy.resize(half * 2, pll(1, 0));
	}
	ll init(int node, int ns, int ne, vector<ll>& arr) {
		if (ns == ne) return item[node] = arr[ns];
		int mid = (ns + ne) / 2;
		return item[node] = (init(node * 2, ns, mid, arr) + init(node * 2 + 1, mid + 1, ne, arr)) % MOD;
	}
	void propagate(int node, int ns, int ne) {
		if (lazy[node].first == 1 && !lazy[node].second) return;
		item[node] = ((item[node] * lazy[node].first) % MOD + (ne - ns + 1) * lazy[node].second) % MOD;
		if (ns != ne) {
			lazy[node * 2].first = (lazy[node * 2].first * lazy[node].first) % MOD;
			lazy[node * 2].second = (lazy[node * 2].second * lazy[node].first + lazy[node].second) % MOD;
			lazy[node * 2 + 1].first = (lazy[node * 2 + 1].first * lazy[node].first) % MOD;
			lazy[node * 2 + 1].second = (lazy[node * 2 + 1].second * lazy[node].first + lazy[node].second) % MOD;
		}
		lazy[node] = pll(1, 0);
	}
	ll sum(int node, int ns, int ne, int l, int r) {
		propagate(node, ns, ne);
		if (l <= ns && ne <= r) return item[node];
		if (ne < l || r < ns) return 0;
		int mid = (ns + ne) / 2;
		return (sum(node * 2, ns, mid, l, r) + sum(node * 2 + 1, mid + 1, ne, l, r)) % MOD;
	}
	void update(int node, int ns, int ne, int l, int r, ll mul, ll add) {
		propagate(node, ns, ne);
		if (ne < l || r < ns) return;
		if (l <= ns && ne <= r) {
			item[node] = ((item[node] * mul) % MOD + add * (ne - ns + 1)) % MOD;
			if (ns != ne) {
				lazy[node * 2].first = (lazy[node * 2].first * mul) % MOD;
				lazy[node * 2].second = (lazy[node * 2].second * mul + add) % MOD;
				lazy[node * 2 + 1].first = (lazy[node * 2 + 1].first * mul) % MOD;
				lazy[node * 2 + 1].second = (lazy[node * 2 + 1].second * mul + add) % MOD;
			}
			return;
		}
		int mid = (ns + ne) / 2;
		update(node * 2 + 1, mid + 1, ne, l, r, mul, add);
		update(node * 2, ns, mid, l, r, mul, add);
		item[node] = (item[node * 2] + item[node * 2 + 1]) % MOD;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	seg S(n);
	vector<ll> seq(n + 1);
	for (int i = 1; i <= n; ++i) cin >> seq[i];
	S.init(1, 1, n, seq);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int query, l, r;
		ll v;
		cin >> query >> l >> r;

		if (query < 4) {
			cin >> v;
			if (query == 1) S.update(1, 1, n, l, r, 1, v);
			else if (query == 2) S.update(1, 1, n, l, r, v, 0);
			else if (query == 3) S.update(1, 1, n, l, r, 0, v);
		}
		else cout << S.sum(1, 1, n, l, r) << '\n';
	}
}
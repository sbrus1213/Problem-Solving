// BOJ 12858 Range GCD
// GCD & segment tree & lazy propagation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	while (a) {
		ll t = b % a;
		b = a;
		a = t;
	}
	return b;
}

vector<ll> val_item, gcd_item, lazy;
void init(int n) {
	int half = 1;
	for (; half < n; half *= 2);
	val_item.resize(half * 2);
	gcd_item.resize(half * 2);
	lazy.resize(half * 2);
}
void prop(int node, int ns, int ne) {
	if (!lazy[node]) return;
	val_item[node] += lazy[node];
	if (ns != ne) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
ll val_query(int node, int ns, int ne, int idx) {
	prop(node, ns, ne);
	if (ns == ne) return val_item[node];
	int mid = (ns + ne) / 2;
	if (mid < idx) return val_query(node * 2 + 1, mid + 1, ne, idx);
	else return val_query(node * 2, ns, mid, idx);
}
void val_update(int node, int ns, int ne, int l, int r, ll diff) {
	prop(node, ns, ne);
	if (ne < l || r < ns) return;
	if (l <= ns && ne <= r) {
		lazy[node] += diff;
		prop(node, ns, ne);
		return;
	}
	int mid = (ns + ne) / 2;
	val_update(node * 2, ns, mid, l, r, diff);
	val_update(node * 2 + 1, mid + 1, ne, l, r, diff);
}
ll gcd_query(int node, int ns, int ne, int l, int r) {
	if (l <= ns && ne <= r) return gcd_item[node];
	if (ne < l || r < ns) return 0;
	int mid = (ns + ne) / 2;
	return gcd(gcd_query(node * 2, ns, mid, l, r), gcd_query(node * 2 + 1, mid + 1, ne, l, r));
}
void gcd_update(int node, int ns, int ne, int idx, ll x) {
	if (ns == ne) {
		gcd_item[node] = x;
		return;
	}
	int mid = (ns + ne) / 2;
	if (mid < idx) gcd_update(node * 2 + 1, mid + 1, ne, idx, x);
	else gcd_update(node * 2, ns, mid, idx, x);
	gcd_item[node] = gcd(gcd_item[node * 2], gcd_item[node * 2 + 1]);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	init(n);
	vector<ll> seq(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> seq[i];
		val_update(1, 1, n, i, i, seq[i]);
	}
	for (int i = 1; i < n; ++i)
		gcd_update(1, 1, n - 1, i, abs(seq[i + 1] - seq[i]));

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		ll t, a, b; cin >> t >> a >> b;
		if (t) {
			val_update(1, 1, n, a, b, t);
			ll al, ar, bl, br;
			if (a > 1) {
				al = val_query(1, 1, n, a - 1);
				ar = val_query(1, 1, n, a);
				gcd_update(1, 1, n - 1, a - 1, abs(ar - al));
			}
			if (b < n) {
				bl = val_query(1, 1, n, b);
				br = val_query(1, 1, n, b + 1);
				gcd_update(1, 1, n - 1, b, abs(br - bl));
			}
		}
		else cout << gcd(val_query(1, 1, n, a), gcd_query(1, 1, n - 1, a, b - 1)) << '\n';
	}
}
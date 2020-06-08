// BOJ 17943 도미노 예측
// Segment tree (Prefix Sum 으로도 가능)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Seg {
	int n, half;
	vector<ll> item;
	Seg(int n_) : n(n_) {
		for (half = 1; half < n; half <<= 1);
		item = vector<ll>(half * 2);
	}
	void init(vector<ll>& v) {
		for (int i = 0; i < n; ++i) item[i + half] = v[i];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] ^ item[i * 2 + 1];
	}
	ll xorq(int l, int r) {
		ll ret = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) ret ^= item[l++];
			if (!(r % 2)) ret ^= item[r--];
			l >>= 1; r >>= 1;
		}
		return ret;
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	vector<ll> ij(n);
	for (int i = 0; i < n - 1; ++i)
		cin >> ij[i];

	Seg seg(n - 1);
	seg.init(ij);

	while (q--) {
		ll c, x, y, d;
		cin >> c >> x >> y;
		x--; y--;
		if (!c) cout << seg.xorq(x, y - 1) << '\n';
		else {
			cin >> d;
			ll xx = seg.xorq(x, y - 1);
			cout << (d ^ xx) << '\n';
		}
	}
}
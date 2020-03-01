// BOJ 11505 구간 곱 구하기
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int mod = 1000000007;

struct seg {
	int half;
	vector<ll> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = (item[i * 2] * item[i * 2 + 1]) % mod;
	}
	ll mul(int l, int r) {
		ll res = 1;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res = (res * item[l++]) % mod;;
			if (!(r % 2)) res = (res * item[r--]) % mod;
			l >>= 1, r >>= 1;
		}
		return res;
	}
	void update(int idx, ll x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = (item[idx * 2] * item[idx * 2 + 1]) % mod;
			idx >>= 1;
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	seg S(n);
	S.init(n);

	for (int i = 0; i < m + k; ++i) {
		int comm, x;
		ll y;
		cin >> comm >> x >> y;

		if (comm == 1) S.update(x - 1, y);
		else cout << S.mul(x - 1, y - 1) << '\n';
	}
}
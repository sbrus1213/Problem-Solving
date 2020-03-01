// BOJ 2042 구간 합 구하기
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct seg {
	int half;
	vector<ll> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
	}
	ll sum(int l, int r) {
		ll res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += item[l++];
			if (!(r % 2)) res += item[r--];
			l >>= 1, r >>= 1;
		}
		return res;
	}
	void update(int idx, ll x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] + item[idx * 2 + 1];
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
		int comm;
		ll x, y;
		cin >> comm >> x >> y;

		if (comm == 1) S.update(x - 1, y);
		else cout << S.sum(x - 1, y - 1) << '\n';
	}
}
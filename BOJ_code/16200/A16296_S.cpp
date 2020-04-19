// BOJ 16296 Daily Division
// segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct seg {
	int n, half;
	vector<ll> item;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
	}
	void init() {
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
	}
	ll sum(int l, int r) {
		ll res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += item[l++];
			if (!(r % 2)) res += item[r--];
			l >>= 1; r >>= 1;
		}
		return res;
	}
	int get(double cnt) {
		int idx = 1;
		while (idx < half) {
			idx <<= 1;
			if (cnt > (double)item[idx]) {
				cnt -= item[idx];
				idx += 1;
			}
		}
		return idx - half;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] + item[idx * 2 + 1];
			idx >>= 1;
		}
	}
};

ll diff(seg& S, int id) {
	ll lsum = S.sum(0, id - 1), rsum = S.sum(id + 1, S.n - 1);
	if (S.item[id + S.half] % 2) {
		if (lsum < rsum) lsum += 1;
		else rsum += 1;
	}
	return abs(lsum - rsum);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	seg S(n);
	S.init();

	for (int i = 0; i < q; ++i) {
		int j, x; cin >> j >> x;
		S.update(j, x);

		int mid = S.get((double)S.item[1] / 2);

		ll can1 = diff(S, mid), ans = mid;
		if (mid >= 1) {
			int can2 = diff(S, mid - 1);
			if (can1 >= can2) {
				can1 = can2;
				ans = mid - 1;
			}
		}
		if (mid <= n - 2) {
			int can2 = diff(S, mid + 1);
			if (can1 > can2) {
				can1 = can2;
				ans = mid + 1;
			}
		}
		cout << ans << '\n';
	}
}
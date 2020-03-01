// BOJ 16978 ¼ö¿­°ú Äõ¸® 22
// offline query

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int mxn = 100001;

struct one {
	int i, v;
};
struct two {
	int l, r, k, idx;
	ll res;
};
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

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	seg S(n);
	S.init();

	int q; cin >> q;
	vector<one> oq;
	vector<two> tq;
	for (int i = 0; i < q; ++i) {
		int c; cin >> c;
		if (c == 1) {
			int idx, v; cin >> idx >> v;
			oq.push_back({ --idx, v });
		}
		else {
			int l, r, k; cin >> k >> l >> r;
			tq.push_back({ --l, --r, k, i });
		}
	}

	sort(tq.begin(), tq.end(), [&](two a, two b) {
		return a.k < b.k;
		});
	int i = 0;
	for (auto& q : tq) {
		while (i < q.k) {
			S.update(oq[i].i, oq[i].v);
			++i;
		}
		q.res = S.sum(q.l, q.r);
	}

	sort(tq.begin(), tq.end(), [&](two a, two b) {
		return a.idx < b.idx;
		});
	for (auto& q : tq) cout << q.res << '\n';
}
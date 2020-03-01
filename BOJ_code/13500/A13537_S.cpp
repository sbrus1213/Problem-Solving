// BOJ 13537 ¼ö¿­°ú Äõ¸®1
// Offline query & segment tree

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct seg {
	int n, half;
	vector<int> item;
	seg(int n_) :n(n_) {
		for (half = 1; half < n_; half <<= 1);
		item.resize(half * 2);
	}
	void init() {
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
	}
	int sum(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += item[l++];
			if (!(r % 2)) res += item[r--];
			l >>= 1; r >>= 1;
		}
		return res;
	}
	void update(int idx) {
		idx += half;
		item[idx]++;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] + item[idx * 2 + 1];
			idx >>= 1;
		}
	}
};
struct query {
	int l, r, k, idx, res;
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<pii> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i].first;
		seq[i].second = i;
	}
	sort(seq.begin(), seq.end(), [&](pii a, pii b) {
		return a.first > b.first;
		});

	int q; cin >> q;
	vector<query> Q(q);
	for (int i = 0; i < q; ++i) {
		int l, r, k; cin >> l >> r >> k;
		Q[i] = { l - 1, r - 1, k, i };
	}
	sort(Q.begin(), Q.end(), [&](query a, query b) {
		return a.k > b.k;
		});

	seg S(n);
	for (int i = 0, j = 0; i < q; ++i) {
		int l = Q[i].l, r = Q[i].r, k = Q[i].k;
		while (j < n && seq[j].first > k) {
			S.update(seq[j].second);
			j++;
		}
		Q[i].res = S.sum(l, r);
	}

	sort(Q.begin(), Q.end(), [&](query a, query b) {
		return a.idx < b.idx;
		});
	for (int i = 0; i < q; ++i) cout << Q[i].res << '\n';
}
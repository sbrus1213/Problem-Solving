// BOJ 13334 Ã¶·Î
// Segment tree

#include <iostream>
#include <vector>
#include <map>
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
	void update(int idx, int x) {
		idx += half;
		item[idx] += x;
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

	vector<pii > P(n);
	vector<int> Y(n);
	for (int i = 0; i < n; ++i) {
		cin >> P[i].first >> P[i].second;
		if (P[i].first > P[i].second) swap(P[i].first, P[i].second);
		Y[i] = P[i].second;
	}
	sort(P.begin(), P.end());

	int yc = 0; map<int, int> yd;
	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int yy : Y) yd[yy] = ++yc;

	seg S(yc + 1);
	for (int i = 0; i < n; ++i)
		S.update(yd[P[i].second], 1);

	int d, ans = 0; cin >> d;
	for (int i = 0; i < n; ++i) {
		int xx = P[i].first + d;
		if (yd[xx]) xx = yd[xx];
		else xx = lower_bound(Y.begin(), Y.end(), xx) - Y.begin();
		ans = max(ans, S.sum(0, xx));
		S.update(yd[P[i].second], -1);
	}
	cout << ans;
}
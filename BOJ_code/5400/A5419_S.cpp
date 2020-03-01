// BOJ 5419 ºÏ¼­Ç³
// sweeping algorithm & segment tree

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

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		vector<pii > P(n);
		vector<int> Y(n);
		for (int i = 0; i < n; ++i) {
			cin >> P[i].first >> P[i].second;
			Y[i] = P[i].second;
		}

		sort(P.begin(), P.end(), [&](pii a, pii b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
			});

		int yc = 0;
		map<int, int> yd;
		sort(Y.begin(), Y.end());
		for (int i = 0; i < n; ++i)
			if (!yd[Y[i]]) yd[Y[i]] = ++yc;
		for (int i = 0; i < n; ++i) P[i].second = yd[P[i].second];

		int yn = yd.size();
		long long ans = 0;
		seg S(yn + 1);
		for (int i = 0; i < n; ++i) {
			ans += S.sum(0, P[i].second);
			S.update(P[i].second);
		}

		cout << ans << '\n';
	}
}
// BOJ 2357 ÃÖ¼Ú°ª°ú ÃÖ´ñ°ª
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
const int INF = (int)1e9 + 7;

struct seg {
	int half;
	vector<pii> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 0; i < n; ++i) cin >> item[i + half].first, item[i + half].second = item[i + half].first;
		for (int i = half - 1; i; --i) {
			item[i].first = min(item[i * 2].first, item[i * 2 + 1].first);
			item[i].second = max(item[i * 2].second, item[i * 2 + 1].second);
		}
	}
	pii minmax(int l, int r) {
		pii res = pii(INF, 0);
		l += half; r += half;
		while (l <= r) {
			if (l % 2) {
				res.first = min(res.first, item[l].first);
				res.second = max(res.second, item[l++].second);
			}
			if (!(r % 2)) {
				res.first = min(res.first, item[r].first);
				res.second = max(res.second, item[r--].second);
			}
			l >>= 1, r >>= 1;
		}
		return res;
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	seg S(n);
	S.init(n);

	for (int i = 0; i < m; ++i) {
		int l, r;
		pii res;
		cin >> l >> r;

		res = S.minmax(l - 1, r - 1);
		cout << res.first << ' ' << res.second << '\n';
	}
}
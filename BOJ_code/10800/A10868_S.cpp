// BOJ 10868 ÃÖ¼Ú°ª
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (int)1e9 + 7;

struct seg {
	int half;
	vector<int> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = min(item[i * 2], item[i * 2 + 1]);
	}
	int minn(int l, int r) {
		int res = INF;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res = min(res, item[l++]);
			if (!(r % 2)) res = min(res, item[r--]);
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
		cin >> l >> r;

		cout << S.minn(l - 1, r - 1) << '\n';
	}
}
// BOJ 1306 ´Þ·Á¶ó È«ÁØ
// Sliding window & segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct  seg
{
	int half;
	vector<int> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	int max_(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res = max(res, item[l++]);
			if (!(r % 2)) res = max(res, item[r--]);
			l >>= 1; r >>= 1;
		}
		return res;
	}
	void upd_(int i, int x) {
		i += half;
		item[i] = x;
		i >>= 1;
		while (i) {
			item[i] = max(item[i * 2], item[i * 2 + 1]);
			i >>= 1;
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, sz;
	cin >> n >> m;
	sz = 2 * m - 1;

	vector<int> light(n);
	for (int i = 0; i < n; ++i) cin >> light[i];

	seg S(2 * m - 1);
	for (int i = 0; i < sz; ++i) {
		S.upd_(i, light[i]);
	}

	cout << S.max_(0, sz - 1) << ' ';
	for (int i = sz, j = 0; i < n; ++i, ++j) {
		S.upd_(j % sz, light[i]);
		cout << S.max_(0, sz - 1) << ' ';
	}
}
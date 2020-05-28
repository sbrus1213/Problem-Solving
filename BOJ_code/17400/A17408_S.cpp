// BOJ 17408 수열과 쿼리 24
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Seg {
	int n, half;
	vector<int> mx, mx2;
	Seg(int n_) : n(n_) {
		for (half = 1; half < n; half <<= 1);
		mx = vector<int>(half * 2);
		mx2 = vector<int>(half * 2);
	}
	void init(vector<int>& v) {
		for (int i = 0; i < n; ++i) mx[i + half] = v[i];
		int tmp[4];
		for (int i = half - 1; i; --i) {
			tmp[0] = mx[i * 2], tmp[1] = mx2[i * 2];
			tmp[2] = mx[i * 2 + 1], tmp[3] = mx2[i * 2 + 1];
			sort(tmp, tmp + 4);
			mx[i] = tmp[3], mx2[i] = tmp[2];
		}
	}
	int sum(int l, int r) {
		vector<int> tmp;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) {
				tmp.push_back(mx[l]);
				tmp.push_back(mx2[l++]);
			}
			if (!(r % 2)) {
				tmp.push_back(mx[r]);
				tmp.push_back(mx2[r--]);
			}
			l >>= 1; r >>= 1;
		}
		sort(tmp.rbegin(), tmp.rend());
		return tmp[0] + tmp[1];
	}
	void update(int idx, int x) {
		idx += half;
		mx[idx] = x;
		int tmp[4];
		while (idx >>= 1) {
			tmp[0] = mx[idx * 2], tmp[1] = mx2[idx * 2];
			tmp[2] = mx[idx * 2 + 1], tmp[3] = mx2[idx * 2 + 1];
			sort(tmp, tmp + 4);
			mx[idx] = tmp[3], mx2[idx] = tmp[2];
		}
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	Seg seg(n);
	seg.init(v);

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int c, l, r; cin >> c >> l >> r;
		if (c == 1) {
			l--;
			seg.update(l, r);
		}
		else {
			l--; r--;
			cout << seg.sum(l, r) << '\n';
		}
	}
}
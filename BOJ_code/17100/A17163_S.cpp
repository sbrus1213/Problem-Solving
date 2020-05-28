// BOJ 17163 가희의 수열놀이 (Large)
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Seg {
	int n, half;
	vector<int> item;
	Seg(int n_) : n(n_) {
		for (half = 1; half < n; half <<= 1);
		item = vector<int>(2 * half);
		for (int i = 1; i < 2 * half; ++i) item[i] = 1;
	}
	int mx(int l, int r) {
		l += half, r += half;
		int ret = -1e7;
		while (l <= r) {
			if (l % 2) ret = max(ret, item[l++]);
			if (!(r % 2)) ret = max(ret, item[r--]);
			l >>= 1, r >>= 1;
		}
		return ret;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx] = x;
		while (idx >>= 1) {
			item[idx] = max(item[idx * 2], item[idx * 2 + 1]);
		}
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int q, mod; cin >> q >> mod;

	if (q <= mod) {
		while (q--) {
			int c; cin >> c;
			if (c == 1) cin >> c;
			else if (c == 3) cout << -1 << '\n';
		}
		return 0;
	}

	vector<int> seq;
	vector<vector<int>> idx(mod);
	Seg seg(mod);
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
			int num; cin >> num; num %= mod;
			idx[num].push_back(seq.size());
			seg.update(num, -1 * seq.size());
			seq.push_back(num);
		}
		else if (c == 2) {
			if (seq.empty()) continue;
			int del = seq.back(); seq.pop_back();
			idx[del].pop_back();
			if (idx[del].empty()) seg.update(del, 1);
			else seg.update(del, -idx[del].back());
		}
		else if (c == 3) {
			int mx = seg.mx(0, mod - 1);
			if (mx == 1) cout << -1 << '\n';
			else cout << seq.size() + mx << '\n';
		}
	}
}
// BOJ 5676 음주코딩
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg {
	int half;
	vector<int> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 0; i < n; ++i) {
			cin >> item[i + half];
			if (item[i + half]) item[i + half] = item[i + half] > 0 ? 1 : -1;
		}
		for (int i = half - 1; i; --i) item[i] = item[i * 2] * item[i * 2 + 1];
	}
	int mul(int l, int r) {
		int res = 1;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res *= item[l++];
			if (!(r % 2)) res *= item[r--];
			l >>= 1, r >>= 1;
		}
		return res;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = item[idx * 2] * item[idx * 2 + 1];
			idx >>= 1;
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	while (cin >> n >> k) {
		seg S(n);
		S.init(n);

		for (int i = 0; i < k; ++i) {
			char comm;
			cin >> comm;
			if (comm == 'C') {
				int i, x;
				cin >> i >> x;
				if (!x) S.update(i - 1, x);
				else if (x > 0) S.update(i - 1, 1);
				else S.update(i - 1, -1);
			}
			else {
				int l, r, res;
				cin >> l >> r;
				res = S.mul(l - 1, r - 1);
				if (!res) cout << res;
				else if (res == 1) cout << '+';
				else cout << '-';
			}
		}

		cout << '\n';
	}
}
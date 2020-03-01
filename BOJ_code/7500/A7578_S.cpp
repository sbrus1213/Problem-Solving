// BOJ 7578 °øÀå
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct seg {
	int half;
	vector<int> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	int sum(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res += item[l++];
			if (!(r % 2)) res += item[r--];
			l >>= 1, r >>= 1;
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

int idx[1000001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n;

	seg S(n);

	for (int i = 0; i < n; ++i) {
		cin >> x;
		idx[x] = i;
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		res += S.sum(idx[x] + 1, n - 1);
		S.update(idx[x], 1);
	}
	cout << res;
}
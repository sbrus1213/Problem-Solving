// BOJ 1321 ±∫¿Œ
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg {
	int n, half;
	vector<int> item;
	seg(int n) :n(n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init() {
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
	}
	int query(int k) {
		int idx = 1;
		while (idx < half) {
			idx <<= 1;
			if (item[idx] < k) {
				k -= item[idx];
				idx += 1;
			}
		}
		return idx - half;
	}
	void update(int idx, int diff) {
		idx += half;
		while (idx) {
			item[idx] += diff;
			idx >>= 1;
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;

	seg s(n);
	s.init();

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int comm, idx, diff, k;
		cin >> comm;
		if (comm == 1) {
			cin >> idx >> diff;
			s.update(idx - 1, diff);
		}
		else {
			cin >> k;
			cout << s.query(k) + 1 << '\n';
		}
	}
}
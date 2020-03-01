// BOJ 3653 영화 수집
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg {
	int half;
	vector<int> item, idx;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 0; i < n; ++i) item[i + half] = 1;
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
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

void init(int n, seg& S, vector<int>& idx) {
	S.init(n);
	for (int i = 0; i < n; ++i) idx[n - i] = i;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, movie;
		cin >> n >> m;

		vector<int> idx(n + 1);
		seg S(n + m + 1);
		init(n, S, idx);

		for (int i = 0; i < m; ++i) {
			cin >> movie;

			cout << S.sum(idx[movie] + 1, n + m) << ' ';

			S.update(n + i, 1);
			S.update(idx[movie], 0);
			idx[movie] = n + i;
		}
		cout << '\n';
	}
}
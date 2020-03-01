// BOJ 1517 버블 소트
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
#define BtoE(vec) vec.begin(), vec.end()

struct seg {
	int half;
	vector<int> item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 0; i < n; ++i)
			item[i + half] = 1;
		for (int i = half - 1; i > 0; --i)
			item[i] = item[i * 2] + item[i * 2 + 1];
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

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n;

	vector<Pii > idx;
	seg S(n);
	S.init(n);

	for (int i = 0; i < n; ++i) {
		cin >> x;
		idx.push_back(Pii(x, i));
	}
	sort(BtoE(idx), greater<Pii >());

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		auto tmp = idx[i];
		res += S.sum(tmp.second + 1, n - 1);
		S.update(tmp.second, 0);
	}

	cout << res;
}
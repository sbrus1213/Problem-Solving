// BOJ 3745 ¿À¸§¼¼
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
	int maxx(int l, int r) {
		int res = 0;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res = max(res, item[l++]);
			if (!(r % 2)) res = max(res, item[r--]);
			l >>= 1, r >>= 1;
		}
		return res;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx] = x;
		idx >>= 1;
		while (idx) {
			item[idx] = max(item[idx * 2], item[idx * 2 + 1]);
			idx >>= 1;
		}
	}
};

bool comp(Pii a, Pii b) {
	if (a.first < b.first) return true;
	else if (a.first > b.first) return false;
	return a.second > b.second;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	while (cin >> n) {
		vector<Pii > price;
		seg S(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			price.push_back(Pii(x, i));
		}
		sort(BtoE(price), comp);

		for (auto tmp : price)
			S.update(tmp.second, S.maxx(0, tmp.second - 1) + 1);

		cout << S.item[1] << '\n';
	}
}
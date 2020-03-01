// BOJ 14428 ¼ö¿­°ú Äõ¸® 16
// Segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Pii = pair<int, int>;
#define BtoE(vec) vec.begin(), vec.end()
const int INF = 1e9 + 7;

Pii min_(Pii a, Pii b) {
	if (a.first < b.first) return a;
	else if (a.first == b.first && a.second < b.second) return a;
	return b;
}

struct seg {
	int half;
	vector<Pii > item;
	seg(int n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(int n) {
		for (int i = 1; i <= n; ++i) cin >> item[i + half].first, item[i + half].second = i;
		for (int i = half - 1; i; --i) item[i] = min_(item[i * 2], item[i * 2 + 1]);
	}
	int minn(int l, int r) {
		Pii res = Pii(INF, 3 * half);
		l += half; r += half;
		while (l <= r) {
			if (l % 2) res = min_(res, item[l++]);
			if (!(r % 2)) res = min_(res, item[r--]);
			l >>= 1, r >>= 1;
		}
		return res.second;
	}
	void update(int idx, int x) {
		idx += half;
		item[idx].first = x;
		idx >>= 1;
		while (idx) {
			item[idx] = min_(item[idx * 2], item[idx * 2 + 1]);
			idx >>= 1;
		}
	}
};

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;

	seg S(n + 1);
	S.init(n);

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x, idx, y, z;
		cin >> x;
		if (x == 1) {
			cin >> idx >> y;
			S.update(idx, y);
		}
		else if (x == 2) {
			cin >> y >> z;
			cout << S.minn(y, z) << '\n';
		}
	}
}
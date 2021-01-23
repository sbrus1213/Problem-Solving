// BOJ 5817 고통받는 난쟁이들
// segment tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

struct Seg {
	int n, half;
	vector<int> max_item, min_item;
	Seg(int n_) : n(n_) {
		for (half = 1; half < n; half <<= 1);
		max_item = min_item = vector<int>(half * 2);
	}
	void init(vector<int>& v) {
		for (int i = 0; i < n; ++i)
			max_item[i + half] = min_item[i + half] = v[i];
		for (int i = half - 1; i; --i) {
			max_item[i] = max(max_item[i * 2], max_item[i * 2 + 1]);
			min_item[i] = min(min_item[i * 2], min_item[i * 2 + 1]);
		}
	}
	pii query(int l, int r) {
		int mn = n * 2, mx = -1;
		l += half; r += half;
		while (l <= r) {
			if (l % 2) {
				mx = max(mx, max_item[l]);
				mn = min(mn, min_item[l++]);
			}
			if (!(r % 2)) {
				mx = max(mx, max_item[r]);
				mn = min(mn, min_item[r--]);
			}
			l >>= 1; r >>= 1;
		}
		return pii(mn, mx);
	}
	void update(int idx, int x) {
		idx += half;
		max_item[idx] = min_item[idx] = x;
		while (idx >>= 1) {
			max_item[idx] = max(max_item[idx * 2], max_item[idx * 2 + 1]);
			min_item[idx] = min(min_item[idx * 2], min_item[idx * 2 + 1]);
		}
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	vector<int> man_pos(n), pos_who(n);
	for (int i = 0; i < n; ++i) {
		cin >> pos_who[i];
		pos_who[i]--;
		man_pos[pos_who[i]] = i;
	}

	Seg seg(n);
	seg.init(man_pos);

	while (m--) {
		int q, a, b; cin >> q >> a >> b;
		a--; b--;
		if (q == 1) {
			swap(pos_who[a], pos_who[b]);
			seg.update(pos_who[a], a);
			seg.update(pos_who[b], b);
		}
		else {
			auto tmp = seg.query(a, b);
			if (b - a != tmp.second - tmp.first)
				cout << "NO\n";
			else cout << "YES\n";
		}
	}
}
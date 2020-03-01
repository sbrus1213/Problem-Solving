// BOJ 2243 »çÅÁ»óÀÚ
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
		for (int i = 0; i < n; ++i) cin >> item[i + half];
		for (int i = half - 1; i; --i) item[i] = item[i * 2] + item[i * 2 + 1];
	}
	int get(int cnt) {
		int idx = 1;
		while (idx < half) {
			if (cnt > item[idx * 2]) {
				cnt -= item[idx * 2];
				idx = idx * 2 + 1;
			}
			else {
				idx *= 2;
			}
		}
		return idx - half;
	}
	void update(int idx, int diff) {
		idx += half;
		item[idx] += diff;
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

	int n;
	seg S(1000001);
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a;

		if (a == 1) {
			cin >> b;
			c = S.get(b);
			cout << c << '\n';
			S.update(c, -1);
		}
		else if (a == 2) {
			cin >> b >> c;
			S.update(b, c);
		}
	}
}
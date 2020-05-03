// BOJ 11087 Bobby's Bet
// È®·ü

#include <iostream>
#include <algorithm>
using namespace std;
using ld = long double;

inline int nck(int n, int k) {
	int ret = 1;
	for (int i = k + 1; i <= n; ++i) ret *= i;
	for (int i = 1; i <= n - k; ++i) ret /= i;
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int r, s, x, y, w; cin >> r >> s >> x >> y >> w;

		ld q = (ld)(r - 1) / s;
		ld p = (ld)1 - q;
		ld res = 0;
		for (int i = x; i <= y; ++i) {
			ld tmp = nck(y, i);
			for (int j = 1; j <= i; ++j) tmp *= p;
			for (int j = 1; j <= y - i; ++j) tmp *= q;
			res += tmp;
		}
		if (res * w > 1) cout << "yes\n";
		else cout << "no\n";
	}
}
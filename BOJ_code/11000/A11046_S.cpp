// BOJ 11046 ÆÓ¸°µå·Ò??
// manacher algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> seq(2 * n + 1);
	for (int i = 1; i < 2 * n; i += 2) cin >> seq[i];

	int p = 0, r = 0;
	vector<int> l(2 * n + 1);
	for (int i = 0; i <= 2 * n; ++i) {
		if (i <= r) l[i] = min(r - i, l[2 * p - i]);
		while (i - l[i] - 1 >= 0 && i + l[i] + 1 <= 2 * n && seq[i - l[i] - 1] == seq[i + l[i] + 1])
			l[i]++;
		if (i + l[i] > r) {
			p = i; r = i + l[i];
		}
	}

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int s, e, mid; cin >> s >> e;
		s = 2 * (s - 1) + 1; e = 2 * (e - 1) + 1;
		mid = (s + e) / 2;
		if (l[mid] >= e - mid) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
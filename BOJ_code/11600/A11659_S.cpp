// BOJ 11659 구간 합 구하기4
// Prefix Sum

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, i, prefixsum[100'001] = { 0 };

	cin >> n >> m;

	for (i = 1; i <= n; ++i) {
		int x;

		cin >> x;

		prefixsum[i] = prefixsum[i - 1] + x;
	}

	for (i = 0; i < m; ++i) {
		int l, r;

		cin >> l >> r;
		if (l > r) swap(l, r);

		cout << prefixsum[r] - prefixsum[l - 1] << '\n';
	}
}
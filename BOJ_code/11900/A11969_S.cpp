// BOJ 11969 Breed Counting
// Prefix sum

#include <iostream>
using namespace std;

int n, q, cnt[100001][3];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		int x;

		cin >> x;

		cnt[i][x - 1] = cnt[i - 1][x - 1] + 1;
		cnt[i][x % 3] = cnt[i - 1][x % 3];
		cnt[i][(x + 1) % 3] = cnt[i - 1][(x + 1) % 3];
	}

	for (int i = 0; i < q; ++i) {
		int l, r;

		cin >> l >> r;

		for (int j = 0; j < 3; ++j) cout << cnt[r][j] - cnt[l - 1][j] << ' ';
		cout << '\n';
	}
}
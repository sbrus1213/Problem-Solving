// BOJ 1301 비즈 공예
// dynamic programming

#include <iostream>
using namespace std;

int n, m, cnt[5], color[40];

int go(int i) {
	if (i == m) return 1;

	int res = 0;
	for (int j = 0; j < n; ++j) {
		if (j == color[i - 1] || j == color[i - 2]) continue;
		if (!cnt[j]) continue;
		color[i] = j; cnt[j]--;
		res += go(i + 1);
		cnt[j]++;
	}
	return res;
}
int  main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> cnt[i];
		m += cnt[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		color[0] = i; cnt[i]--;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			color[1] = j; cnt[j]--;
			for (int k = 0; k < n; ++k) {
				if (i == k || j == k) continue;
				color[2] = k; cnt[k]--;
				ans += go(3);
				cnt[k]++;
			}
			cnt[j]++;
		}
		cnt[i]++;
	}
	cout << ans;
}
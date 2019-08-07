// BOJ 2098 외판원 순회
// Dynamic Programming & Bit mask

#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

int n, cost[16][16], dp[1 << 16][16];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> cost[i][j];

	for (int i = 1; i < (1 << n); ++i)
		for (int j = 0; j < n; ++j)
			dp[i][j] = INF;

	dp[1][0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i & (1 << k)) continue;
				if (!cost[j][k]) continue;

				dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + cost[j][k]);
			}
		}
	}

	int res = INF;
	for (int i = 1; i < n; ++i)
		if (cost[i][0])
			res = min(dp[(1 << n) - 1][i] + cost[i][0], res);

	cout << res;
}
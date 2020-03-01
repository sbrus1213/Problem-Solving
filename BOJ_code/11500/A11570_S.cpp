// BOJ 11570 »ØªÛ¿« µ‡øß
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 2e9 + 7;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector<vector<int> > dp(n + 1, vector<int>(n + 1, INF));
	dp[1][0] = dp[0][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;

			int next = max(i, j) + 1, tmp;

			if (!i) tmp = dp[i][j];
			else tmp = dp[i][j] + abs(a[next] - a[i]);
			dp[next][j] = min(dp[next][j], tmp);

			if (!j) tmp = dp[i][j];
			else tmp = dp[i][j] + abs(a[next] - a[j]);
			dp[i][next] = min(dp[i][next], tmp);
		}
	}

	int ans = INF;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, dp[i][n]);
		ans = min(ans, dp[n][i]);
	}
	cout << ans;
}
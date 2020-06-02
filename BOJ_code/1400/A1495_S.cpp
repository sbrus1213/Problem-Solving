// BOJ 1495 기타리스트
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, s, m; cin >> n >> s >> m;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	dp[0][s] = 1;

	for (int i = 1; i <= n; ++i) {
		int v; cin >> v;
		for (int j = 0; j <= m; ++j) {
			if (j >= v) dp[i][j] |= dp[i - 1][j - v];
			if (j + v <= m) dp[i][j] |= dp[i - 1][j + v];
		}
	}

	for (int i = m; i >= 0; --i)
		if (dp[n][i]) {
			cout << i;
			return 0;
		}
	cout << -1;
}
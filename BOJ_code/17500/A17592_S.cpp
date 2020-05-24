// BOJ 17592 Running Routes
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int adj[501][501], dp[501][501];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> adj[i][j];

	for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = adj[i][i + 1];
	for (int i = 0; i < n - 2; ++i)
		dp[i][i + 2] = adj[i][i + 1] | adj[i][i + 2] | adj[i + 1][i + 2];
	for (int k = 3; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			int j = i + k;
			if (j >= n) break;
			dp[i][j] = dp[i + 1][j - 1] + adj[i][j];
			for (int l = i; l < j; ++l)
				dp[i][j] = max(dp[i][j], dp[i][l] + dp[l + 1][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			ans = max(ans, dp[i][j]);

	cout << ans;
}
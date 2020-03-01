// BOJ 11051 이항 계수 2
// Combinatorics & Dynamic Programming

#include <iostream>
using namespace std;
const int mod = 1e4 + 7;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, dp[1001][1001];

	cin >> n >> k;

	for (int i = 0; i <= n; ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
	}

	cout << dp[n][k];
}
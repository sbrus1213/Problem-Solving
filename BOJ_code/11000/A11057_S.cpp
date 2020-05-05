// BOJ 11057 오르막 수
// dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 10007;

int dp[1001][10];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 0; i < 10; ++i) dp[1][i] = 1;

	for (int i = 2; i <= n; ++i)
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= j; ++k)
				dp[i][j] += dp[i - 1][k];
			dp[i][j] %= mod;
		}

	int ans = 0;
	for (int i = 0; i < 10; ++i) ans += dp[n][i];
	cout << ans % mod;
}
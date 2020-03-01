// BOJ 14945 ∫“¿Â≥≠
// Dynamic Programming

#include <iostream>
using namespace std;

const int mod = 10007;
int n, dp[101][101][101] = {}, res = 0;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	dp[2][1][2] = 1;

	for (int l = 2; l < n; ++l)
		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				dp[l + 1][i][j] = (dp[l + 1][i][j] + dp[l][i][j]) % mod;
				dp[l + 1][i][j + 1] = (dp[l + 1][i][j + 1] + dp[l][i][j]) % mod;
				if (i + 1 != j)
					dp[l + 1][i + 1][j] = (dp[l + 1][i + 1][j] + dp[l][i][j]) % mod;
				dp[l + 1][i + 1][j + 1] = (dp[l + 1][i + 1][j + 1] + dp[l][i][j]) % mod;
			}

	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			res = (res + dp[n][i][j]) % mod;
	res = (res * 2) % mod;

	cout << res;
}
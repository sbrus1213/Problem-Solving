// BOJ 1562 계단 수
// Dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1e9;

int dp[101][10][1 << 10];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 1; i < 10; ++i) dp[1][i][(1 << i)] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < (1 << 10); ++j) {
			for (int k = 0; k < 10; ++k) {
				if (!(j & (1 << k))) continue;
				if (k == 0) dp[i + 1][1][j | (1 << 1)] = (dp[i + 1][1][j | (1 << 1)] + dp[i][k][j]) % mod;
				else if (k == 9) dp[i + 1][8][j | (1 << 8)] = (dp[i + 1][8][j | (1 << 8)] + dp[i][k][j]) % mod;
				else {
					dp[i + 1][k - 1][j | (1 << (k - 1))] = (dp[i + 1][k - 1][j | (1 << (k - 1))] + dp[i][k][j]) % mod;
					dp[i + 1][k + 1][j | (1 << (k + 1))] = (dp[i + 1][k + 1][j | (1 << (k + 1))] + dp[i][k][j]) % mod;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; ++i)
		ans = (ans + dp[n][i][(1 << 10) - 1]) % mod;
	cout << ans;
}
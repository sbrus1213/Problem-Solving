// BOJ 1010 다리 놓기
// Dynamic Programming

#include <iostream>
using namespace std;

int dp[30][30];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while (tc--) {
		int n, m, res = 0;

		cin >> n >> m;

		for (int i = 0; i <= m; ++i) {
			dp[i][0] = dp[i][i] = 1;

			for (int j = 1; j < i; ++j) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[m][n] << '\n';
	}
}
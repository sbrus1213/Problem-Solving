// BOJ 17391 무한 부스터
// Dynamic programming

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, boost[301][301], dp[301][301];

	cin >> n >> m;

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> boost[i][j];

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 1; k <= boost[i][j]; ++k) {
				if (i + k < n) {
					if (!dp[i + k][j]) dp[i + k][j] = dp[i][j] + 1;
					else dp[i + k][j] = min(dp[i + k][j], dp[i][j] + 1);
				}
				if (j + k < m) {
					if (!dp[i][j + k]) dp[i][j + k] = dp[i][j] + 1;
					else dp[i][j + k] = min(dp[i][j + k], dp[i][j] + 1);
				}
			}
		}
	}

	cout << dp[n - 1][m - 1] - 1;
}
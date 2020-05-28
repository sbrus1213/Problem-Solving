// BOJ 17070 파이프 옮기기 1
// dynamic programming

#include <iostream>
#include <vector>
using namespace std;

int home[17][17], dp[17][17][3];

int go(int r, int c, int dir) {
	if (dp[r][c][dir] != -1) return dp[r][c][dir];

	dp[r][c][dir] = 0;
	if (dir == 0 && !home[r][c - 1] && c > 1)
		dp[r][c][dir] = go(r, c - 1, 0) + go(r, c - 1, 2);
	if (dir == 1 && !home[r - 1][c] && r > 1)
		dp[r][c][dir] = go(r - 1, c, 1) + go(r - 1, c, 2);
	if (dir == 2 && !home[r - 1][c] && !home[r][c - 1] && !home[r - 1][c - 1] && r > 1 && c > 1)
		dp[r][c][dir] = go(r - 1, c - 1, 0) + go(r - 1, c - 1, 1) + go(r - 1, c - 1, 2);
	return dp[r][c][dir];
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> home[i][j];
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		}

	if (home[n][n]) {
		cout << 0;
		return 0;
	}

	dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = 0;
	dp[2][1][0] = dp[2][1][1] = dp[2][1][2] = 0;
	dp[1][2][0] = 1;
	int ans = go(n, n, 0) + go(n, n, 1) + go(n, n, 2);
	cout << ans;
}
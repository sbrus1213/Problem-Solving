// BOJ 5528 달려라 IOI 열차
// dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[2001][2001][2];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	a = 'a' + a;
	b = 'b' + b;

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 'I') {
			dp[i][0][0] = 1;
			if (a[i] != a[i - 1]) dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][0] + 1);
			ans = max(ans, dp[i][0][0]);
		}
		else if (dp[i - 1][0][0] && a[i] != a[i - 1]) dp[i][0][0] = dp[i - 1][0][0] + 1;
	}
	for (int i = 1; i <= m; ++i) {
		if (b[i] == 'I') {
			dp[0][i][1] = 1;
			if (b[i] != b[i - 1]) dp[0][i][1] = max(dp[0][i][1], dp[0][i - 1][1] + 1);
			ans = max(ans, dp[0][i][1]);
		}
		else if (dp[0][i - 1][1] && b[i] != b[i - 1]) dp[0][i][1] = dp[0][i - 1][1] + 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			// a에서 할 경우 i j 0
			if (a[i] == 'I') {
				dp[i][j][0] = 1;
				if (a[i - 1] != a[i]) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + 1);
				if (a[i] != b[j]) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1] + 1);
				ans = max(ans, dp[i][j][0]);
			}
			else {
				dp[i][j][0] = 0;
				if (a[i - 1] != a[i] && dp[i - 1][j][0]) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + 1);
				if (a[i] != b[j] && dp[i - 1][j][1]) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1] + 1);
			}

			// b에서 할 경우 i j 1
			if (b[j] == 'I') {
				dp[i][j][1] = 1;
				if (a[i] != b[j]) dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] + 1);
				if (b[j - 1] != b[j]) dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] + 1);
				ans = max(ans, dp[i][j][1]);
			}
			else {
				dp[i][j][1] = 0;
				if (a[i] != b[j] && dp[i][j - 1][0]) dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] + 1);
				if (b[j - 1] != b[j] && dp[i][j - 1][1]) dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] + 1);
			}
		}
	}

	cout << ans;
}
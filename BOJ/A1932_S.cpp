// BOJ 1932 Á¤¼ö »ï°¢Çü
// Dynaic Programming

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, res = 0, triangle[501][501], dp[501][501];

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			cin >> triangle[i][j];

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][0] + triangle[i][0];
		dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];

		for (int j = 1; j < i; ++j)
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
	}

	for (int i = 0; i < n; ++i)
		res = max(res, dp[n - 1][i]);

	cout << res;
}
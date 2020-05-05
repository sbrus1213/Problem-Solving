// BOJ 11048 이동하기
// dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int x; cin >> x;
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j])) + x;
		}

	cout << dp[n][m];
}
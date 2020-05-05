// BOJ 1149 RGB 거리
// dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i) {
		int r, g, b; cin >> r >> g >> b;
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b;
	}
	cout << min({ dp[n][0], dp[n][1], dp[n][2] });
}
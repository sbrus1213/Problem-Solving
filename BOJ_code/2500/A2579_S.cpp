// BOJ 2579 계단 오르기
// Dynamic Programming

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, stair[305], dp[305][2] = { 0 }, i;

	cin >> n;

	for (i = 1; i <= n; ++i) {
		cin >> stair[i];
	}

	dp[1][0] = stair[1];
	dp[2][0] = stair[2];
	dp[2][1] = stair[1] + stair[2];

	for (i = 3; i <= n; ++i) {
		dp[i][0] = max(dp[i - 2][0] + stair[i], dp[i][0]);
		dp[i][0] = max(dp[i - 2][1] + stair[i], dp[i][0]);

		dp[i][1] = max(dp[i - 1][0] + stair[i], dp[i][1]);
	}

	cout << max(dp[n][0], dp[n][1]);
}
// BOJ 11066 파일 합치기
// Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;

int file[501], dp[501][501];
int solve(int i, int j) {
	if (i == j) return dp[i][j] = 0;

	dp[i][j] = INF;
	for (int k = i; k < j; ++k) {
		if (dp[i][k] == -1) solve(i, k);
		if (dp[k + 1][j] == -1) solve(k + 1, j);
		dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + file[j] - file[i - 1]);
	}
	return dp[i][j];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; ++i) cin >> file[i];
		for (int i = 1; i <= n; ++i) file[i] += file[i - 1];

		memset(dp, -1, sizeof(dp));
		cout << solve(1, n) << '\n';
	}
}
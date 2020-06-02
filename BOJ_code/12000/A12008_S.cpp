// BOJ 12008 262144
// dynamic programming & sparse table

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> seq(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> seq[i];

	// dp
	// i i에서 부터
	// j j를 만들 수 있으면 그다음 구간시작은 어딘지?
	vector<vector<int>> dp(n + 1, vector<int>(70));
	for (int i = 1; i <= n; ++i)
		dp[i][seq[i]] = i + 1;

	// dp[i][j]
	// dp[i][j] = dp[dp[i][j-1]][j-1]
	for (int j = 1; j < 69; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (dp[i][j + 1]) continue;
			if (dp[i][j] == n + 1) continue;
			if (dp[i][j] && dp[dp[i][j]][j])
				dp[i][j + 1] = dp[dp[i][j]][j];
		}
	}

	int ans = 0;
	for (int j = 1; j < 70; ++j)
		for (int i = 1; i <= n; ++i)
			if (dp[i][j]) ans = max(ans, j);
	cout << ans;
}
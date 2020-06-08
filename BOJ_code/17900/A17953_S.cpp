// BOJ 17953 디저트
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> man[10], dp[10];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		man[i] = dp[i] = vector<int>(n + 1);
		for (int j = 1; j <= n; ++j)
			cin >> man[i][j];
		dp[i][1] = man[i][1];
	}

	for (int j = 2; j <= n; ++j)
		for (int i = 0; i < m; ++i)
			for (int k = 0; k < m; ++k)
				if (i == k) dp[i][j] = max(dp[i][j], dp[i][j - 1] + man[i][j] / 2);
				else dp[i][j] = max(dp[i][j], dp[k][j - 1] + man[i][j]);

	int ans = 0;
	for (int i = 0; i < m; ++i)
		ans = max(ans, dp[i][n]);
	cout << ans;
}
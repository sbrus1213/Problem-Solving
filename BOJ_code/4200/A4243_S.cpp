// BOJ 4243 보안 업체
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int n, s;
vector<ll> dist;
ll dp[101][101];
ll solve(int i, int j, int rem) {
	if (!rem) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int l = min(i, j), r = max(i, j);

	dp[i][j] = INF;

	if (r != n) dp[i][j] = min(dp[i][j], solve(l, r + 1, rem - 1) + rem * (dist[r + 1] - dist[j]));
	if (l != 1) dp[i][j] = min(dp[i][j], solve(r, l - 1, rem - 1) + rem * (dist[j] - dist[l - 1]));

	return dp[i][j];
}
ll solve(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = INF;

	if (i < j && s < j) {	// i, j -> l, r 로 주어지고 r이 출발점으로 줄어들 수 있는 경우
		ll tmp = n - j + i;
		solve(i, j - 1); solve(j - 1, i);
		dp[i][j] = min(dp[i][j - 1] + (dist[j] - dist[j - 1]) * tmp, dp[j - 1][i] + (dist[j] - dist[i]) * tmp);
	}
	if (j < i && j < s) {	// i, j -> r, l 로 주어지고 l이 출발점으로 줄어들 수 있는 경우
		ll tmp = n - i + j;
		solve(j + 1, i); solve(i, j + 1);
		dp[i][j] = min(dp[i][j + 1] + (dist[j + 1] - dist[j]) * tmp, dp[j + 1][i] + (dist[i] - dist[j]) * tmp);
	}
	return dp[i][j];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> s;

		dist.resize(n + 1, 0);
		for (int i = 2; i <= n; ++i) cin >> dist[i];
		for (int i = 2; i <= n; ++i) dist[i] += dist[i - 1];

		memset(dp, -1, sizeof(dp));
		//dp[s][s] = 0;
		cout << solve(s, s, n - 1) << '\n';
		//		cout << min(solve(1, n), solve(n, 1)) << '\n';
	}
}
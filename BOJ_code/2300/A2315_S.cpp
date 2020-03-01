// BOJ 2315 °¡·Îµî ²ô±â
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000000007;

int n, s;
vector<int> loca, elec, elecsum;
int dp[1001][1001][2];

void solve(int l, int r) {
	if (dp[l][r][0] != -1) return;

	dp[l][r][0] = dp[l][r][1] = INF;

	if (l < s) {
		solve(l + 1, r);
		int tmp = elecsum[l] - elecsum[0] + elecsum[n] - elecsum[r];
		dp[l][r][0] = min(dp[l + 1][r][0] + (loca[l + 1] - loca[l]) * tmp, dp[l + 1][r][1] + (loca[r] - loca[l]) * tmp);
	}
	if (s < r) {
		solve(l, r - 1);
		int tmp = elecsum[l - 1] - elecsum[0] + elecsum[n] - elecsum[r - 1];
		dp[l][r][1] = min(dp[l][r - 1][0] + (loca[r] - loca[l]) * tmp, dp[l][r - 1][1] + (loca[r] - loca[r - 1]) * tmp);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;

	loca.resize(n + 1);
	elec.resize(n + 1);
	elecsum.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> loca[i] >> elec[i];
	for (int i = 1; i <= n; ++i) elecsum[i] = elecsum[i - 1] + elec[i];

	memset(dp, -1, sizeof(dp));
	dp[s][s][0] = dp[s][s][1] = 0;
	solve(1, n);

	cout << min(dp[1][n][0], dp[1][n][1]);
}
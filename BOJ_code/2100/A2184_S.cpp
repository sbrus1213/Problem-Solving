// BOJ 2184 ±èÄ¡ ¹è´Þ
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000000007;

int n, l, s;
vector<int> loca;
int dp[1001][1001][2];

void solve(int l, int r, int rem) {
	if (dp[l][r][0] != -1) return;

	dp[l][r][0] = dp[l][r][1] = INF;

	if (l < s) {
		solve(l + 1, r, rem + 1);
		dp[l][r][0] = min(dp[l + 1][r][0] + (loca[l + 1] - loca[l]) * rem,
							dp[l + 1][r][1] + (loca[r] - loca[l]) * rem);
	}
	if (s < r) {
		solve(l, r - 1, rem + 1);
		dp[l][r][1] = min(dp[l][r - 1][0] + (loca[r] - loca[l]) * rem,
							dp[l][r - 1][1] + (loca[r] - loca[r - 1]) * rem);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> l;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		loca.push_back(x);
	}
	loca.push_back(l);
	sort(loca.begin(), loca.end());
	s = lower_bound(loca.begin(), loca.end(), l) - loca.begin();

	memset(dp, -1, sizeof(dp));
	dp[s][s][0] = dp[s][s][1] = 0;
	solve(0, n, 1);

	cout << min(dp[0][n][0], dp[0][n][1]);
}
// BOJ 5626 Á¦´Ü
// Dynamic Programming 

#include <iostream>
#include <vector>
using namespace std;
const int mod = 1000000007;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> h(n);
	for (int i = 0; i < n; ++i) cin >> h[i];

	int maxh = n / 2;
	vector<vector<int> > dp(2, vector<int>(maxh + 1));
	dp[0][0] = (!h[0] || h[0] == -1);
	for (int i = 1; i < n; ++i) {
		int cur = i & 1, pre = !(i & 1);

		if (h[i] == -1) {
			dp[cur][0] = (dp[pre][0] + dp[pre][1]) % mod;
			dp[cur][maxh] = (dp[pre][maxh] + dp[pre][maxh - 1]) % mod;
			for (int j = 1; j < maxh; ++j) {
				dp[cur][j] = (dp[pre][j - 1] + dp[pre][j + 1]) % mod;
				dp[cur][j] = (dp[pre][j] + dp[cur][j]) % mod;
			}
		}
		else {
			if (h[i] > maxh) continue;

			fill(dp[cur].begin(), dp[cur].end(), 0);
			dp[cur][h[i]] = dp[pre][h[i]];
			if (h[i] > 0) dp[cur][h[i]] = (dp[cur][h[i]] + dp[pre][h[i] - 1]) % mod;
			if (h[i] < maxh) dp[cur][h[i]] = (dp[cur][h[i]] + dp[pre][h[i] + 1]) % mod;
		}
	}

	cout << dp[1 - (n & 1)][0];
}
// BOJ 17271 리그 오브 레전설 (small)
// dynamic programming

#include <iostream>
#include <vector>
using namespace std;
const int mod = 1000000007;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	vector<int> dp;

	cin >> n >> m;
	dp.resize(n + 1);

	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (i >= m) dp[i] = (dp[i - 1] + dp[i - m]) % mod;
		else dp[i] = dp[i - 1];
	}
	cout << dp[n];
}
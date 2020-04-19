// BOJ 17545 Deceptive Dice
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	vector<double> dp(k);
	dp[0] = (double)(n + 1) / 2;

	for (int i = 1; i < k; ++i) {
		for (int j = 1; j <= n; ++j)
			dp[i] += dp[i - 1] > j ? dp[i - 1] : j;
		dp[i] /= n;
	}

	cout << fixed;
	cout.precision(8);
	cout << dp[k - 1];
}
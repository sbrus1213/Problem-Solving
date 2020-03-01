// BOJ 2240 자두나무
// dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, w, jadu[1001], dp[31][2];

	cin >> t >> w;
	for (int i = 1; i <= t; ++i) cin >> jadu[i];

	dp[w][0] = (jadu[1] == 1);
	dp[w - 1][1] = (jadu[1] == 2);
	for (int i = 2; i <= t; ++i) {
		for (int j = 0; j < w; j++) {
			dp[j][0] = max(dp[j][0], dp[j + 1][1]) + (jadu[i] == 1);
			dp[j][1] = max(dp[j][1], dp[j + 1][0]) + (jadu[i] == 2);
		}
		dp[w][0] += (jadu[i] == 1);
		dp[w][1] += (jadu[i] == 2);
	}

	int res = -1;
	for (int i = 0; i <= w; i++) {
		res = max(res, dp[i][0]);
		res = max(res, dp[i][1]);
	}

	cout << res;
}
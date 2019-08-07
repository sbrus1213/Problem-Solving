// BOJ 5626 Á¦´Ü
// Dynamic Programming 

#include <iostream>
using namespace std;
#define mod (1e9+7)

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, height[10001], dp[2][5000] = {};

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> height[i];

	dp[0][0] = (height[0] == 0 || height[0] == -1);
	for (int i = 1; i < n; ++i) {
		if (height[i] == -1) {
			for (int j = 0; j < 5000; ++j) {
				dp[i & 1][j] = dp[!(i & 1)][j];

				if (j + 1 < 5000)
					dp[i & 1][j] = (dp[i & 1][j] + dp[!(i & 1)][j + 1]) % (int)mod;

				if (j - 1 >= 0)
					dp[i & 1][j] = (dp[i & 1][j] + dp[!(i & 1)][j - 1]) % (int)mod;
			}
		}
		else {
			if (height[i] >= 5000)
				continue;

			fill(dp[i & 1], dp[i & 1] + 5000, 0);

			dp[i & 1][height[i]] = dp[!(i & 1)][height[i]];

			if (height[i] + 1 < 5000)
				dp[i & 1][height[i]] = (dp[i & 1][height[i]] + dp[!(i & 1)][height[i] + 1]) % (int)mod;

			if (height[i] - 1 >= 0)
				dp[i & 1][height[i]] = (dp[i & 1][height[i]] + dp[!(i & 1)][height[i] - 1]) % (int)mod;
		}
	}

	cout << dp[!(n % 2)][0];
}
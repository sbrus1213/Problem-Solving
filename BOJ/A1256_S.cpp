// BOJ 1256 »çÀü
// Dynamic Programming & Combinatorics

#include <iostream>
#include <string>
using namespace std;
#define INF 1e9

int dp[201][201];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	string res = "";

	cin >> n >> m >> k;

	for (int i = 0; i <= n + m; ++i) {
		dp[i][0] = dp[i][i] = 1;

		for (int j = 1; j < i; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

			if (dp[i][j] > INF)
				dp[i][j] = INF + 7;
		}
	}

	if (dp[n + m][m] < k) {
		cout << -1;
		return 0;
	}

	while (n > 0 || m > 0) {
		if (dp[n + m - 1][m] >= k) {
			res.push_back('a');

			--n;
		}
		else {
			res.push_back('z');

			k -= dp[n + m - 1][m];
			--m;
		}
	}

	cout << res;
}
// BOJ 1006 습격자 초라기
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 40000;

int n, w;
vector<int> val[2];
vector<vector<int>> dp;

int go(int i, int state) {
	if (i <= 1 || dp[i][state] != inf) return dp[i][state];

	int& ret = dp[i][state];
	if (state == 0) {
		for (int j = 0; j < 5; ++j) ret = min(ret, go(i - 1, j) + 2);
	}
	else if (state == 1 && val[0][i] + val[1][i] <= w) {
		for (int j = 0; j < 5; ++j) ret = min(ret, go(i - 1, j) + 1);
	}
	else if (state == 2 && val[0][i] + val[0][i - 1] <= w) {
		for (int j = 7; j < 9; ++j) ret = min(ret, go(i - 1, j) + 2);
	}
	else if (state == 3 && val[1][i] + val[1][i - 1] <= w) {
		for (int j = 5; j < 7; ++j) ret = min(ret, go(i - 1, j) + 2);
	}
	else if (state == 4 && val[0][i] + val[0][i - 1] <= w && val[1][i] + val[1][i - 1] <= w) {
		for (int j = 0; j < 5; ++j) ret = min(ret, go(i - 2, j) + 2);
	}
	else if (state == 5) {
		for (int j = 0; j < 5; ++j) ret = min(ret, go(i - 1, j) + 1);
	}
	else if (state == 6 && val[0][i] + val[0][i - 1] <= w) {
		for (int j = 7; j < 9; ++j) ret = min(ret, go(i - 1, j) + 1);
	}
	else if (state == 7) {
		for (int j = 0; j < 5; ++j) ret = min(ret, go(i - 1, j) + 1);
	}
	else if (state == 8 && val[1][i] + val[1][i - 1] <= w) {
		for (int j = 5; j < 7; ++j) ret = min(ret, go(i - 1, j) + 1);
	}
	return ret;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> w;

		val[0] = vector<int>(n + 1);
		val[1] = vector<int>(n + 1);
		for (int i = 0; i < 2; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> val[i][j];

		int ans = inf;
		dp = vector<vector<int>>(n + 1, vector<int>(9, inf));
		fill(dp[0].begin(), dp[0].end(), 0);

		dp[1][0] = 2;
		for (int i = 0; i < 5; ++i) ans = min(ans, go(n, i));

		if (val[0][1] + val[1][1] <= w) {
			for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
			dp[1][1] = 1;
			for (int i = 0; i < 5; ++i) ans = min(ans, go(n, i));
		}

		if (val[0][1] + val[0][n] <= w) {
			for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
			dp[1][2] = 2;
			for (int i = 7; i < 9; ++i) ans = min(ans, go(n, i));
		}

		if (val[1][1] + val[1][n] <= w) {
			for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
			dp[1][3] = 2;
			for (int i = 5; i < 7; ++i) ans = min(ans, go(n, i));
		}

		if (val[0][1] + val[0][n] <= w && val[1][1] + val[1][n] <= w) {
			for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
			dp[1][4] = 2;
			for (int i = 0; i < 5; ++i) ans = min(ans, go(n - 1, i));
		}

		for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
		dp[1][5] = 1;
		for (int i = 0; i < 5; ++i) ans = min(ans, go(n, i));

		if (val[0][1] + val[0][n] <= w) {
			for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
			dp[1][6] = 1;
			for (int i = 7; i < 9; ++i) ans = min(ans, go(n, i));
		}

		for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
		dp[1][7] = 1;
		for (int i = 0; i < 5; ++i) ans = min(ans, go(n, i));

		if (val[1][1] + val[1][n] <= w) {
			for (int i = 1; i <= n; ++i) fill(dp[i].begin(), dp[i].end(), inf);
			dp[1][8] = 1;
			for (int i = 5; i < 7; ++i) ans = min(ans, go(n, i));
		}

		cout << ans << '\n';
	}
}
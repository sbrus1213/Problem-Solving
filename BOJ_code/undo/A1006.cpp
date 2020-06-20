// BOJ 1006 습격자 초라기
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 40000;

int n, w;
int val[10001][2], dp[10001][3];

void go(int st) {
	for (int i = st; i < n; ++i) {
		// 2 둘다
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][2] + 1);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);
		dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + 2);
		if (val[i + 1][0] + val[i + 1][1] <= w) dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + 1);
		if (i + 2 <= n) {
			if (val[i + 1][0] + val[i + 2][0] <= w && val[i + 1][1] + val[i + 2][1] <= w)
				dp[i + 2][2] = min(dp[i + 2][2], dp[i][2] + 2);
			if (val[i + 1][0] + val[i + 2][0] <= w) dp[i + 2][2] = min(dp[i + 2][2], dp[i][2] + 3);
			if (val[i + 1][1] + val[i + 2][1] <= w) dp[i + 2][2] = min(dp[i + 2][2], dp[i][2] + 3);
		}

		// 0 위만
		if (val[i][1] + val[i + 1][1] <= w) dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);

		// 1 아래만
		if (val[i][0] + val[i + 1][0] <= w) dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1);
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> w;

		for (int j = 0; j < 2; ++j)
			for (int i = 1; i <= n; ++i)
				cin >> val[i][j];

		if (n == 1) {
			if (val[1][0] + val[1][1] <= w) cout << 1 << '\n';
			else cout << 2 << '\n';
			continue;
		}

		dp[0][0] = dp[0][1] = dp[0][2] = 0;

		int ans = inf;

		for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = dp[i][2] = inf;
		go(0);
		ans = min(ans, dp[n][2]);

		if (val[1][0] + val[n][0] <= w && val[1][1] + val[n][1] <= w) {
			for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = dp[i][2] = inf;
			dp[1][0] = dp[1][1] = 1; dp[1][2] = 2;
			go(1);
			ans = min(ans, dp[n - 1][2]);
		}

		if (val[1][0] + val[n][0] <= w) {
			for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = dp[i][2] = inf;
			dp[1][0] = dp[1][1] = 1; dp[1][2] = 2;
			if (val[1][1] + val[2][1] <= w) dp[2][1] = 2, dp[2][2] = 3;
			go(1);
			ans = min(ans, dp[n][1]);
		}

		if (val[1][1] + val[n][1] <= w) {
			for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = dp[i][2] = inf;
			dp[1][0] = dp[1][1] = 1; dp[1][2] = 2;
			if (val[1][0] + val[2][0] <= w) dp[2][0] = 2, dp[2][2] = 3;
			go(1);
			ans = min(ans, dp[n][0]);
		}

		cout << ans << '\n';
	}
}
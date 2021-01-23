// BOJ 1006 습격자 초라기
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 40000;

int n, w;
int val[10001][2], dp[10001][3];

// dp[i][0/1/2]
// 0 -> i번째 열의 윗칸만 채울 때 최소
// 1 -> i번째 열의 아랫칸만 채울 때 최소
// 2 -> i번째 열의 두칸 모두 채울 때 최소
void go(int st) {
	for (int i = st; i < n; ++i) {
		int up = 2 - (val[i][0] + val[i + 1][0] <= w ? 1 : 0);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][2] + 1);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + up);

		int down = 2 - (val[i][1] + val[i + 1][1] <= w ? 1 : 0);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + down);

		int updown = 2 - (val[i + 1][0] + val[i + 1][1] <= w ? 1 : 0);
		dp[i + 1][2] = min({
			dp[i + 1][2], dp[i][2] + updown,
			dp[i + 1][0] + 1, dp[i + 1][1] + 1
			});

		if (i > 0 && up + down < 4)
			dp[i + 1][2] = min(dp[i + 1][2], dp[i - 1][2] + up + down);
	}
}

void init_inf() {
	for (int i = 1; i <= n; ++i)
		dp[i][0] = dp[i][1] = dp[i][2] = inf;
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

		int ans = inf;

		// 1번째 - n번째 연결 x
		init_inf();
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		dp[1][0] = dp[1][1] = 1;
		dp[1][2] = 2 - (val[1][0] + val[1][1] <= w);
		go(1);
		ans = min(ans, dp[n][2]);

		// 1번째 - n번째 위아래 모두 연결
		if (val[1][0] + val[n][0] <= w && val[1][1] + val[n][1] <= w) {
			init_inf();
			dp[0][2] = inf;
			dp[1][2] = 2;
			go(1);
			ans = min(ans, dp[n - 1][2]);
		}

		// 1번째 - n번째 위만 연결
		if (val[1][0] + val[n][0] <= w) {
			init_inf();
			dp[0][2] = inf;
			dp[1][0] = 1; dp[1][2] = 2;
			go(1);
			ans = min(ans, dp[n][1]);
		}

		// 1번째 - n번째 아래만 연결
		if (val[1][1] + val[n][1] <= w) {
			init_inf();
			dp[0][2] = inf;
			dp[1][1] = 1; dp[1][2] = 2;
			go(1);
			ans = min(ans, dp[n][0]);
		}

		cout << ans << '\n';
	}
}
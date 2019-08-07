// BOJ 11062 카드게임
// Dynamic Programming 

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
int card[1001], dp[1001][1001][2];

void game(int i, int j, bool who) {
	if (i + 1 == j) {
		dp[i][j][who] = max(card[i], card[j]);
		dp[i][j][!who] = min(card[i], card[j]);
		return;
	}

	if (dp[i + 1][j][!who] == -1) game(i + 1, j, !who);
	if (dp[i][j - 1][!who] == -1) game(i, j - 1, !who);

	if (dp[i + 1][j][who] + card[i] > dp[i][j - 1][who] + card[j]) {
		dp[i][j][who] = dp[i + 1][j][who] + card[i];
		dp[i][j][!who] = dp[i + 1][j][!who];
	}
	else {
		dp[i][j][who] = dp[i][j - 1][who] + card[j];
		dp[i][j][!who] = dp[i][j - 1][!who];
	}
}*/

int card[1001], dp[1001][1001];

int game(int i, int j, int cnt) {
	if (i == j) {
		return dp[i][j] = (cnt % 2 ? card[i] : 0);
	}

	if (dp[i + 1][j] == -1) game(i + 1, j, cnt + 1);
	if (dp[i][j - 1] == -1) game(i, j - 1, cnt + 1);

	if (cnt % 2) dp[i][j] = max(dp[i + 1][j] + card[i], dp[i][j - 1] + card[j]);
	else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);

	return dp[i][j];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while (tc--) {
		int n;
		memset(dp, -1, sizeof(dp));

		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> card[i];

		if (n == 1) {
			cout << card[0] << '\n';
			continue;
		}

		cout << game(0, n - 1, 1) << '\n';
	}
}
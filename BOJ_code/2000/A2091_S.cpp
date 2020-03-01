// BOJ 2091 µ¿Àü
// Dynamic programming

#include <iostream>
using namespace std;

int dp[10001][5];
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, item[4] = { 1,5, 10, 25 }, lim[4];
	cin >> x;
	for (int i = 0; i < 4; ++i) cin >> lim[i];

	for (int xx = 0; xx <= x; ++xx) {
		for (int k = 0; k < 4; ++k) {
			if (xx && dp[xx][0] == 0) continue;
			for (int i = 1; i <= lim[k] - dp[xx][k + 1]; ++i) {
				int xxx = xx + item[k] * i;
				if (xxx > x) break;
				if (dp[xxx][0] < dp[xx][0] + i) {
					dp[xxx][0] = dp[xx][0] + i;
					for (int j = 1; j <= 4; ++j)
						dp[xxx][j] = dp[xx][j];
					dp[xxx][k + 1] += i;
				}
			}
		}
	}

	if (dp[x][0] == 0) cout << "0 0 0 0";
	else for (int i = 1; i < 5; ++i) cout << dp[x][i] << ' ';
}
// BOJ 5569 출근 경로
// Dynamic Programming

#include <iostream>
using namespace std;
#define div 100000

// dp[row][column][최근 이동: 0 - 우/ 1 - 상][최근 두번째 이동: 0 - 우 / 1 - 상]
int w, h, dp[101][101][2][2];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int res;

	cin >> w >> h;

	for (int i = 3; i <= w; ++i) {
		dp[i][2][0][0] = dp[i][2][0][1] = 1;
	}
	for (int i = 3; i <= h; ++i) {
		dp[2][i][1][1] = dp[2][i][1][0] = 1;
	}
	dp[2][2][0][1] = dp[2][2][1][0] = 1;

	for (int i = 3; i <= w; ++i) {
		for (int j = 3; j <= h; ++j) {
			dp[i][j][0][0] = (dp[i][j][0][0] + dp[i - 1][j][0][0] + dp[i - 1][j][1][0]) % div;
			dp[i][j][0][1] = (dp[i][j][0][1] + dp[i][j - 1][0][0]) % div;
			dp[i][j][1][0] = (dp[i][j][1][0] + dp[i - 1][j][1][1]) % div;
			dp[i][j][1][1] = (dp[i][j][1][1] + dp[i][j - 1][0][1] + dp[i][j - 1][1][1]) % div;
		}
	}

	res = (dp[w][h][0][0] + dp[w][h][0][1] + dp[w][h][1][0] + dp[w][h][1][1]) % div;

	cout << res;
}
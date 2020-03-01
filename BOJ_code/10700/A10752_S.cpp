// BOJ 10752 Cow Hopscotch
// Dynamic programming

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, dp[16][16] = {};
	char board[16][16];

	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> board[i][j];

	dp[1][1] = 1;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!dp[i][j]) continue;

			char ch = board[i][j];
			for (int ii = i + 1; ii <= r; ii++)
				for (int jj = j + 1; jj <= c; jj++)
					if (board[ii][jj] != ch)
						dp[ii][jj] += dp[i][j];
		}
	}
	cout << dp[r][c];
}
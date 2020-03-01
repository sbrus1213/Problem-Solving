// BOJ 1890 มกวม
// dynamic programming

#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, board[101][101];
	ll cnt[101][101] = { 1 };

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				if (i + board[i][j] < n) cnt[i + board[i][j]][j] += cnt[i][j];
				if (j + board[i][j] < n) cnt[i][j + board[i][j]] += cnt[i][j];
			}
		}
	}
	cout << cnt[n - 1][n - 1];
}
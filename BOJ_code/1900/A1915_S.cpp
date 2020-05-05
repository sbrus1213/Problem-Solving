// BOJ 1915 가장 큰 정사각형
// Dynamic Programming

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char c; cin >> c;
			dp[i][j] = c - '0';
		}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int m = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] });
			if (dp[i][j]) dp[i][j] = m + 1;
			else dp[i][j] = 0;
			res = max(res, dp[i][j]);
		}
	}

	cout << res * res;
}
// BOJ 11066 파일 합치기
// Dynamic Programming

#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

int file[501], pxsum[501];
int dp[501][501];

int dynamic(int i, int j) {
	int& res = dp[i][j], tmp = 1e9;

	if (i == j) return res = 0;
	if (i + 1 == j) return res = file[i] + file[j];


	for (int k = i; k < j; ++k) {
		if (dp[i][k] == INF) dynamic(i, k);
		if (dp[k + 1][j] == INF) dynamic(k + 1, j);

		tmp = min(tmp, dp[i][k] + dp[k + 1][j]);
	}

	return res = tmp + pxsum[j] - pxsum[i - 1];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;

	cin >> tc;

	while (tc--) {
		int n;

		cin >> n;

		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dp[i][j] = INF;

		for (int i = 1; i <= n; ++i) {
			cin >> file[i];
			pxsum[i] = pxsum[i - 1] + file[i];
		}

		cout << dynamic(1, n) << '\n';
	}
}
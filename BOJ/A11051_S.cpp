// BOJ 11051 이항 계수 2
// Combinatorics & Dynamic Programming

#include <iostream>
using namespace std;
#define div 1e4+7

int dp[1001][1001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	for (int i = 0; i <= n; ++i) {

		dp[i][0] = dp[i][i] = 1;

		for (int j = 1; j < i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % ((int)div);
		}
	}

	cout << dp[n][k];
}
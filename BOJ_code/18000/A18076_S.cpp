// BOJ 18076 Just the Last Digit
// dynamic programming

#include <iostream>
using namespace std;
const int mxn = 501;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int go[mxn][mxn] = {};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			char c; cin >> c;
			go[i][j] = c - '0';
		}

	int dp[mxn][mxn] = {};
	for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = go[i][i + 1];

	for (int k = 2; k < n; ++k) {
		for (int i = 0; i < n - k; ++i) {
			int sum = 0;
			for (int j = i + 1; j < i + k; ++j)
				sum += dp[i][j] * go[j][i + k];
			if (sum % 10 == go[i][i + k]) dp[i][i + k] = 0;
			else dp[i][i + k] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << dp[i][j];
		cout << '\n';
	}
}
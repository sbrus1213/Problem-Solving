// BOJ 2449 Àü±¸
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> col(n);
	for (int i = 0; i < n; ++i)
		cin >> col[i];

	vector<vector<int> > dp(n, vector<int>(n, n + 1));

	for (int i = 0; i < n; ++i) dp[i][i] = 0;

	for (int k = 1; k < n; ++k)
		for (int i = 0; i < n - k; ++i)
			for (int j = i; j < i + k; ++j)
				dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + (col[i] != col[j + 1]));
	cout << dp[0][n - 1];
}
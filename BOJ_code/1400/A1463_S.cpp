// BOJ 1463 1로 만들기
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<int> dp(n + 1, n + 3);

	dp[1] = 0;
	for (int i = 1; i < n; ++i) {
		if (i + 1 <= n) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 <= n) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		if (i * 3 <= n) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
	}
	cout << dp[n];
}
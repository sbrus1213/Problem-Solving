// BOJ 2156 포도주 시식
// dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

int dp[10010], drink[10010];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i) cin >> drink[i];

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (i < 3) dp[i] = dp[i - 1] + drink[i];
		else dp[i] = max({ dp[i - 2] + drink[i], dp[i - 3] + drink[i - 1] + drink[i], dp[i - 1] });
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
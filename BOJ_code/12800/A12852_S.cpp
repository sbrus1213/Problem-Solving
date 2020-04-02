// BOJ 12852 1로 만들기 2
// Dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> dp(n + 1, n + 9);

	dp[1] = 0;
	for (int i = 1; i < n; ++i) {
		if (i + 1 <= n) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 <= n) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		if (i * 3 <= n) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
	}

	vector<int> ans;
	for (int i = n; i != 1;) {
		ans.push_back(i);
		if (!(i % 3) && dp[i / 3] == dp[i] - 1) i /= 3;
		else if (!(i % 2) && dp[i / 2] == dp[i] - 1) i /= 2;
		else if (dp[i - 1] == dp[i] - 1) i -= 1;
	}
	ans.push_back(1);
	cout << dp[n] << '\n';
	for (int x : ans) cout << x << ' ';
}
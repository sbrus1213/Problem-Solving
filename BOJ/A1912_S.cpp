// BOJ 1912 ¿¬¼ÓÇÕ
// Dynamic Programming

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, dp[100001] = {};

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;

		cin >> x;

		if (dp[i - 1] < 0) dp[i] = x;
		else dp[i] = dp[i - 1] + x;
	}

	int res = -1e9;
	for (int i = 1; i <= n; ++i)
		res = max(res, dp[i]);

	cout << res;
}
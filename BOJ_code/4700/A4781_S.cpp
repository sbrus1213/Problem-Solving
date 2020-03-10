// BOJ 4781 ªÁ≈¡ ∞°∞‘
// Knapsack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		int n, k, d; char t;
		cin >> n >> k >> t >> d;
		k = k * 100 + d;

		if (!n) break;

		int c, p, dp[10001] = {};
		for (int i = 1; i <= n; ++i) {
			cin >> c >> p >> t >> d;
			p = p * 100 + d;
			for (int j = p; j <= k; ++j)
				dp[j] = max(dp[j], dp[j - p] + c);
		}
		cout << dp[k] << '\n';
	}
}
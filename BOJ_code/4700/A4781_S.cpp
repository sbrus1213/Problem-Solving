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
		int n, k;
		double m;
		cin >> n >> m;
		k = m * 1e2;

		if (!n) break;

		int c, p;
		int dp[10001] = {};
		for (int i = 1; i <= n; ++i) {
			cin >> c >> m;
			p = (int)(m * 1e2);
			for (int j = p; j <= k; ++j)
				dp[j] = max(dp[j], dp[j - p] + c);
		}
		cout << dp[k] << '\n';
	}
}
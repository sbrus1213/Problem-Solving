// BOJ 7579 ¾Û
// Dynamic Programming - Knapsack

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, memory[101], cost[101], dp[101][10000] = {}, m_sum = 0, c_sum = 0, res;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> memory[i];
		m_sum += memory[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
		c_sum += cost[i];
	}

	dp[0][c_sum] = m_sum;
	for (int i = 0; i < n; ++i) {
		for (int j = c_sum; j >= 0; --j) {
			if (dp[i][j]) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

				if (j - cost[i] >= 0)
					dp[i + 1][j - cost[i]] = max(dp[i + 1][j - cost[i]], dp[i][j] - memory[i]);
			}
		}
	}

	for (int i = 0; i <= 10000; ++i) {
		if (dp[n][i] >= m) {
			res = i;
			break;
		}
	}

	cout << res;
}
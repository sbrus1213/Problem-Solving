// BOJ 14728 º­¶ôÄ¡±â
// Dynamic Programming - Knapsack

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, weight[101], value[101], dp[10001] = {};

	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> weight[i] >> value[i];

	dp[weight[0]] = value[0];
	for (int i = 1; i < n; ++i)
		for (int j = k; j >= weight[i]; --j)
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

	int res = 0;
	for (int i = 0; i <= k; ++i)
		res = max(res, dp[i]);

	cout << res;
}
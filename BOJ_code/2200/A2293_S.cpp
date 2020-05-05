// BOJ 2293 동전 1
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	vector<int> coin(n);
	for (int i = 0; i < n; ++i) cin >> coin[i];

	dp[0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = coin[i]; j <= k; ++j)
			dp[j] += dp[j - coin[i]];

	cout << dp[k];
}
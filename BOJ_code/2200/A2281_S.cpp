// BOJ 2281 데스노트
// dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 2e9;

int n, m;
vector<int> len, dp;

int go(int i) {
	if (dp[i] != inf) return dp[i];

	int sum = len[i], j = i - 1, & ret = dp[i];
	if (i != n) ret = go(i - 1) + (m - sum) * (m - sum);
	else ret = go(i - 1);
	while (1) {
		sum += len[j] + 1;
		if (sum > m || j == 0) break;
		if (i != n) ret = min(ret, go(j - 1) + (m - sum) * (m - sum));
		else ret = min(ret, go(j - 1));
		j--;
	}
	return ret;
}


int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	len = vector<int>(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> len[i];

	dp = vector<int>(n + 1, inf);
	dp[0] = 0;
	cout << go(n);
}
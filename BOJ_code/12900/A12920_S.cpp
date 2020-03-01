// BOJ 12920 Æò¹üÇÑ ¹è³¶ 2
// Dynamic Programming - Knapsack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> weight, value;
	for (int i = 0; i < n; ++i) {
		int w, v, cnt, tmp = 1;
		cin >> w >> v >> cnt;
		while (cnt) {
			if (tmp > cnt) tmp = cnt;
			weight.push_back(w * tmp);
			value.push_back(v * tmp);
			cnt -= tmp;
			tmp *= 2;
		}
	}

	int len = weight.size();
	vector<int> dp(m + 1);
	dp[weight[0]] = value[0];
	for (int i = 1; i < len; ++i)
		for (int j = m; j >= weight[i]; --j)
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

	int res = -1;
	for (int i = 0; i <= m; ++i)
		res = max(res, dp[i]);
	cout << res;
}
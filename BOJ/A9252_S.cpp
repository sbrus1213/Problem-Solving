// BOJ 9252 LCS2
// Dynamic Programming - LCS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;

	cin >> s1 >> s2;

	int l1 = s1.size(), l2 = s2.size();

	for (int i = 1; i <= l1; ++i) {
		for (int j = 1; j <= l2; ++j) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}

	int res = dp[l1][l2], tmp, i = l1, j = l2;
	vector<char> ans;

	tmp = res;
	while (tmp) {
		while (dp[i - 1][j] == tmp)
			--i;
		while (dp[i][j - 1] == tmp)
			--j;
		ans.push_back(s1[i - 1]);
		--i; --j; --tmp;
	}

	cout << res << '\n';
	for (i = res - 1; i >= 0; --i)
		cout << ans[i];
}
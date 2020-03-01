// BOJ 18427 함께 블록 쌓기
// Dynamic programming & knapsack

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int mod = 10007;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, h;
	cin >> n >> m >> h;
	cin.ignore(1);

	vector<vector<int> > block(n);
	for (int i = 0; i < n; ++i) {
		string s;
		getline(cin, s);

		int tmp = 0;
		for (int j = 0; j <= s.size(); ++j) {
			if (j == s.size())
				block[i].push_back(tmp);
			else if (s[j] == ' ') {
				block[i].push_back(tmp);
				tmp = 0;
			}
			else tmp = tmp * 10 + (s[j] - '0');
		}
	}

	int dp[50][1001] = { 1, };

	for (int i = 0; i < block[0].size(); ++i)
		dp[0][block[0][i]] = 1;

	for (int i = 1; i < n; ++i) {
		dp[i][0] = 1;
		for (int k = 0; k <= h; ++k)
			dp[i][k] = dp[i - 1][k];
		for (int j : block[i])
			for (int k = j; k <= h; ++k)
				dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % mod;
	}
	cout << dp[n - 1][h];
}
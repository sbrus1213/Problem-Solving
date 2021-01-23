// BOJ 3793 Common Subsequence
// dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string a, b;

	while (cin >> a >> b) {
		int al = a.length(), bl = b.length();

		vector<vector<int>> dp(al + 1, vector<int>(bl + 1));

		a = 'a' + a;
		b = 'b' + b;
		for (int i = 1; i <= al; ++i)
			for (int j = 1; j <= bl; ++j)
				dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i] == b[j]) });

		cout << dp[al][bl] << '\n';
	}
}
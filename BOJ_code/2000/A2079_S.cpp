// BOJ 2079 팰린드롬
// dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int len = s.size();

	s += '0';
	vector<int> dp(len + 1, len);
	for (int i = 0; i < len; ++i) {
		for (int j = 0; i - j >= 0; ++j) {
			if (s[i - j] == s[i + j]) {
				if (i == j) dp[i + j] = 1;
				else dp[i + j] = min(dp[i + j], dp[i - j - 1] + 1);
			}
			else break;
		}
		for (int j = 0; i - j - 1 >= 0; ++j) {
			if (s[i - j - 1] == s[i + j]) {
				if (i == j + 1) dp[i + j] = 1;
				else dp[i + j] = min(dp[i + j], dp[i - j - 2] + 1);
			}
			else break;
		}
	}

	cout << dp[len - 1];
}
// BOJ 1796 신기한 키보드
// Dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int sz = s.size(), mn = 27;
	int l[26], r[26];
	fill(l, l + 26, -1);
	for (int i = 0; i < sz; ++i) {
		if (l[s[i] - 'a'] == -1) l[s[i] - 'a'] = i;
		r[s[i] - 'a'] = i;
		mn = min(mn, s[i] - 'a');
	}

	vector<vector<int> > dp(26, vector<int>(sz, 1e9));
	for (int i = 0; i < sz; ++i)
		dp[mn][i] = r[mn] + abs(r[mn] - i);

	for (int i = 1; i < 26; ++i) {
		if (l[i] == -1) for (int j = 0; j < sz; ++j) dp[i][j] = dp[i - 1][j];
		else {
			for (int j = 0; j < sz; ++j)
				for (int k = 0; k < sz; ++k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + (r[i] - l[i]) + min(abs(r[i] - k) + abs(l[i] - j), abs(l[i] - k) + abs(r[i] - j)));
		}
	}
	mn = 1e9;
	for (int i = 0; i < sz; ++i) mn = min(mn, dp[25][i]);
	cout << mn + sz;
}
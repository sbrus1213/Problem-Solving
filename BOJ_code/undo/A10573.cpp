// BOJ 10573 증가하는 수
// dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll dp[85][10];

int go(string s) {
	if (s.size() == 1) return dp[1][s[0] - '0'] = 1;

	ll& ret = dp[s.size()][s[0] - '0'];
	if (ret) return ret;

	string cpy = s;
	for (char c = s[0]; c <= s[1]; ++c) {
		cpy[1] = c;
		ret += go(cpy.substr(1));
	}
	for (char c = '0'; c < s[0]; ++c) {
		if(c == '0') 
	}
	if (s[0] == '1') {
		string tmp = "";
		for (int i = 1; i < s.size(); ++i)
			tmp += '9';
		ret += go(tmp);
	}
	else {
		s[0]--;
		ret += go(s);
	}

	return ret;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		string num; cin >> num;

		int len = num.size();
		for (int i = 0; i < len - 1; ++i)
			if (num[i] > num[i + 1]) {
				len = -1;
				break;
			}
		if (len == -1) {
			cout << -1 << '\n';
			continue;
		}

		cout << go(num) << '\n';
	}
}
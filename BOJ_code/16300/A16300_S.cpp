// BOJ 16300 H to O
// ¼öÇÐ

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, ss; int c; cin >> s >> c >> ss;

	int scnt[26] = {}, sscnt[26] = {};
	for (int i = 0; i < s.size();) {
		int ch = s[i++] - 'A', cnt = 0;
		while (i < s.size() && s[i] <= '9') {
			cnt = cnt * 10 + s[i] - '0';
			i++;
		}
		if (!cnt) cnt = 1;
		scnt[ch] += cnt * c;
	}
	for (int i = 0; i < ss.size();) {
		int ch = ss[i++] - 'A', cnt = 0;
		while (i < ss.size() && ss[i] <= '9') {
			cnt = cnt * 10 + ss[i] - '0';
			i++;
		}
		if (!cnt) cnt = 1;
		sscnt[ch] += cnt;
	}
	int ans = 2e9;
	for (int i = 0; i < 26; ++i)
		if (sscnt[i]) ans = min(ans, scnt[i] / sscnt[i]);
	cout << ans;
}
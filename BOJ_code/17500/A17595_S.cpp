// BOJ 17595 Summer Trip 
// 카운팅

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int len = s.size(), exist[26];
	for (int i = 0; i < 26; ++i) exist[i] = len + 10;
	ll ans = 0;
	for (int i = len - 1; i >= 0; --i) {
		int tmp = 0;
		for (int j = 0; j < 26; ++j) {
			if (j == s[i] - 'a') continue;
			if (exist[j] < exist[s[i] - 'a']) tmp++;
		}
		ans += tmp;
		exist[s[i] - 'a'] = i;
	}
	cout << ans;
}
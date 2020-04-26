// BOJ 1541 ภาพ๎น๖ธฐ ฐýศฃ
// greedy 

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int ans = 0, t = 0, f = 0, sz = s.size();
	for (int i = 0; i <= sz; ++i) {
		if (i == sz || !(s[i] >= '0' && s[i] <= '9')) {
			if (f) ans -= t;
			else ans += t;
			t = 0;
			if (i != sz && !f && s[i] == '-') f = 1;
		}
		else {
			t = t * 10 + s[i] - '0';
		}
	}
	cout << ans;
}
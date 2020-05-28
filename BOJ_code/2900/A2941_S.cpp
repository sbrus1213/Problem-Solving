// BOJ 2941 크로아티아 알파벳
// 구현

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int ans = 0, len = s.size();
	for (int i = 0; i < len; ++i) {
		ans++;
		if (i + 1 == len) continue;
		if (s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-')) i++;
		else if (s[i] == 'd' && len && s[i + 1] == '-') i++;
		else if (s[i] == 'd' && i + 2 < len && s[i + 1] == 'z' && s[i + 2] == '=') i += 2;
		else if (s[i] == 'l' && s[i + 1] == 'j') i++;
		else if (s[i] == 'n' && s[i + 1] == 'j') i++;
		else if (s[i] == 's' && s[i + 1] == '=') i++;
		else if (s[i] == 'z' && s[i + 1] == '=') i++;
	}
	cout << ans;
}
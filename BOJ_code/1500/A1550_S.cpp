// BOJ 1550 16진수
// 수학

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	long long ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] <= '9') ans = ans * 16 + (s[i] - '0');
		else ans = ans * 16 + (s[i] - 'A' + 10);
	}
	cout << ans;
}
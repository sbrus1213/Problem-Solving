// BOJ 8958 OXÄûÁî
// ±¸Çö

#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;

		int ans = 0, t = 0;
		for (char c : s) {
			if (c == 'O') ans += ++t;
			else t = 0;
		}
		cout << ans << '\n';
	}
}
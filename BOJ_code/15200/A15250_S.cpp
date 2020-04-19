// BOJ 15250 Palindromic Partitions
// hashing & greedy & palindrome

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const ll mul = 23;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	string s;
	while (tc--) {
		cin >> s;
		int ans = 0, sz = s.size();
		ll a = 0, b = 0, cc = 1;
		for (int i = 0; i < sz / 2; ++i) {
			a = a * mul + (s[i] - '0');
			b = (s[sz - 1 - i] - '0') * cc + b;
			if (a == b) {
				ans += 2;
				a = b = 0;
				cc = 1;
			}
			else {
				cc *= mul;
			}
		}
		if (a || b) ans++;
		else if (sz % 2) ans++;
		cout << ans << '\n';
	}
}
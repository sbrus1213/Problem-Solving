// BOJ 11170 0ÀÇ °³¼ö
// Brute force

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;

		int cnt = 0;
		for (int i = n; i <= m; ++i) {
			int t = i;
			while (1) {
				if (!t) {
					cnt++; break;
				}
				else if (t < 10) break;
				else {
					if (!(t % 10)) cnt++;
					t /= 10;
				}
			}
		}
		cout << cnt << '\n';
	}
}
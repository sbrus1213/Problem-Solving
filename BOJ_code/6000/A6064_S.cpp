// BOJ 60604 카잉 달력
// 수학

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--) {
		int m, n, x, y, ans = -1; cin >> m >> n >> x >> y;

		for (int i = 0; i <= n; ++i) {
			int t = m * i + x;
			if (t % n == y % n) {
				ans = t;
				break;
			}
		}
		cout << ans << '\n';
	}
}
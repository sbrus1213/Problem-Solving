// BOJ 2200 °è»ê±â
// greedy algorithm

#include <iostream>
using namespace std;

int count(int x) {
	int cnt;
	for (cnt = 1; x >= 10; x /= 10, cnt++);
	return cnt;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		int c; cin >> c;
		if (i) {
			if (c) {
				ans += 1 + count(c);
			}
			ans += 2;
		}
		else continue;
	}
	cin >> n;
	if (n) ans += 2 + count(n);
	else ans += 1;
	cout << ans;
}
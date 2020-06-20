// BOJ 1568 새
// 구현

#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int ans = 0;
	for (int x = 1; n;) {
		if (x <= n) n -= x++, ans++;
		else x = 1;
	}
	cout << ans;
}
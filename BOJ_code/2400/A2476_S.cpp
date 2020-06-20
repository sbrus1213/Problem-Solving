// BOJ 2476 주사위 게임
// 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int n; cin >> n;

	int ans = 0;
	while (n--) {
		int a, b, c; cin >> a >> b >> c;

		int tmp = 0;
		if (a == b && b == c) tmp = 10000 + a * 1000;
		else if (a == b || a == c) tmp = 1000 + a * 100;
		else if (b == c) tmp = 1000 + b * 100;
		else tmp = max({ a, b, c }) * 100;
		ans = max(ans, tmp);
	}
	cout << ans;
}